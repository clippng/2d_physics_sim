#include "world_generation.hpp"

#include <cmath>
//#include <random>
#include <iostream>

namespace WorldGenerationTools {
	std::shared_ptr<std::vector<BlockType>> generateWorld(int64_t world_seed, uint32_t world_width, uint32_t world_height) {
		std::shared_ptr<std::vector<BlockType>> world_data(new std::vector<BlockType>((world_height * world_width), NONE));

		std::srand(world_seed);

		//deciede on ground level
		const uint32_t water_level = 100;
		const uint32_t max_slope = 3.0f;

		int32_t slope;
		uint32_t ground_levels[world_width];
		ground_levels[0] = water_level;

		for (uint32_t i = 1; i < world_width; ++i) {
			slope = std::rand() / (RAND_MAX / max_slope);
			if (rand() % 2 == 0) {
				ground_levels[i] = ground_levels[i-1] - slope;
			} else {
				ground_levels[i] = ground_levels[i-1] + slope;			
			}
		}

		// fill in ground
		for (uint32_t i = 0, row = 0; row < world_height; ++row) {
			for (uint32_t column = 0; column < world_width; ++column, ++i) {
				BlockType block;
				if (row > ground_levels[column]) {
					float noise = getNoise(row, column);
					if (noise > 0.3f) { 
						block = DIRT;
					} else if (noise < 0.1f) {
						block = STONE;
					} else {
						block = SAND;
					}
				} else if (row > water_level) {
					block = WATER;
				} else {
					block = NONE;
				}
				
				world_data->at(i) = block;
			}
		}

		// increase stone at lower levels 
		for (uint32_t i = 0, row = 0; row < world_height; ++row) {
			for (uint32_t column = 0; column < world_width; ++column, ++i) {
				float noise = getNoise(row, column);
				if (noise * map(row, world_height, 0, 1, 0) > 0.2) {
					if (row > ground_levels[column]) { world_data->at(i) = STONE; }
				}
			}
		}

		// caves 
		for (uint32_t i = 0, row = 0; row < world_height; ++row) {
			for (uint32_t column = 0; column < world_width; ++column, ++i) {
				float noise = getNoise(map(row, world_height, 0, 5, -5), map(column, world_width, 0, 5, -5));
				if (noise > 0.8) {
					if (row > ground_levels[column] && row > water_level) { world_data->at(i) = NONE; }
				}
				
			}
		}

		

		return world_data;
	}

	uint8_t getHash(int32_t value) { 
		return permutation_table[static_cast<uint8_t>(value)]; 
	}

	float map(const float value, const float input_max, const float input_min, const float target_max, const float target_min) {
		return (value - input_min) / (input_max - input_min) * (target_max - target_min) + target_min;
	}

	float getGradient(int32_t hash, float x_distance, float y_distance) {
		const int32_t hash0 = hash & 0xF3;
		const float u = hash0 < 4 ? x_distance : y_distance;
		const float v = hash0 < 4 ? y_distance : x_distance;
		return ((hash0 & 1) ? -u : u) + ((hash0 & 2) ? -2.0f * v : 2.0f * v);
	}

	float groundHeight(float x_coord) {
		return sin(x_coord * 2) * cos(x_coord / 2) * cos(x_coord / 3) * tan(x_coord / 2);
	}

	// returns range(-1, 1)
	float getNoise(float x_coord, float y_coord) {
		float noise_value0, noise_value1, noise_value2;

		static const float F2 = 0.36602540378443864676372317075293f;  // F2 = (sqrt(3) - 1) / 2 (32 sig. digits)
		static const float G2 = 0.21132486540518711774542560974902f;  // G2 = (3 - sqrt(3)) / 6   = F2 / (1 + 2 * K) (32 sig. digits)

		const float skew = (x_coord + y_coord) * F2;
		const float x_skew = x_coord + skew;
		const float y_skew = y_coord + skew;
		const int32_t i_coord0 = floor(x_skew);
		const int32_t j_coord0 = floor(y_skew);

		const float unskew = static_cast<float>(i_coord0 + j_coord0) * G2;
		const float x_coord0 = x_coord - static_cast<float>(i_coord0 - unskew);
		const float y_coord0 = y_coord - static_cast<float>(j_coord0 - unskew);

		int32_t i_coord1, j_coord1;
		if (x_coord0 > y_coord0) {
			i_coord1 = 1;
			j_coord1 = 0;
		} else {
			i_coord1 = 0;
			j_coord1 = 1;
		}

		const float x_coord1 = x_coord0 - i_coord1 + G2;
		const float y_coord1 = y_coord0 - j_coord1 + G2;
		const float x_coord2 = x_coord0 - 1.0f + 2.0f * G2;
		const float y_coord2 = y_coord0 - 1.0f + 2.0f * G2;

		const int gradient_i_coord0 = getHash(i_coord0 + getHash(j_coord0));
		const int gradient_i_coord1 = getHash(i_coord0 + i_coord1 + getHash(j_coord0 + j_coord1));
		const int gradient_i_coord2 = getHash(i_coord0 + 1 + getHash(j_coord0 + 1));

		float t_coord0 = 0.5f - x_coord0 * x_coord0 - y_coord0 * y_coord0;
		if (t_coord0 < 0.0f) { noise_value0 = 0.0f; } 
		else { t_coord0 *= t_coord0; noise_value0 = t_coord0 * t_coord0 * getGradient(gradient_i_coord0, x_coord0, y_coord0); }

		float t_coord1 = 0.5f - x_coord1 * x_coord1 - y_coord1 * y_coord1;
		if (t_coord1 < 0.0f) { noise_value1 = 0.0f; } 
		else { t_coord1 *= t_coord1; noise_value1 = t_coord1 * t_coord1 * getGradient(gradient_i_coord1, x_coord1, y_coord1); }

		float t_coord2 = 0.5f - x_coord2 * x_coord2 - y_coord2 * y_coord2;
		if (t_coord2 < 0.0f) { noise_value2 = 0.0f; } 
		else { t_coord2 *= t_coord2; noise_value2 = t_coord2 * t_coord2 * getGradient(gradient_i_coord2, x_coord2, y_coord2); }

		return 45.23065f * (noise_value0 + noise_value1 + noise_value2);
	}
}
