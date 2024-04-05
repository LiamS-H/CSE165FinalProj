//
// Created by liams on 4/4/2024.
//
#ifndef TILESET_H
#define TILESET_H

#include <vector>
#include <map>
#include <stdexcept>
#include <iostream>
#include <random>

const std::vector<int> tiles_ids = {0,1,2,3,4,5,6,7};

struct Color {
public:
    float r;
    float g;
    float b;
    Color(float red, float green, float blue) {
        this->r = red;
        this->g = green;
        this->b = blue;
    }
};

Color color_from_id(int tile_id) {
    std::map<int, Color> color_map = {
            {0, Color(0,0,0)},  // Black (empty cell)
            {1, Color(1,0,0)},  // Red
            {2, Color(0,1,0)},  // Green
            {3, Color(0,0,1)}, // Blue
            {4, Color(1,1,0)},  // Yellow
            {5, Color(1,0,1)},  // Purple
            {6, Color(0,1,1)},  // Light Blue
            {7, Color(1, 0.5,0)}   // Orange
    };
    try {
        Color color = color_map.at(tile_id);
        return color;
    } catch (const std::out_of_range& e) {
        std::cerr << "tile_id " << tile_id << "  out of range." << std::endl;
        return {0,0,0};
    }
}

int random_tile() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(1, (int)tiles_ids.size()-1);

    int random_number = dis(gen);

    return random_number;
}

std::vector<int> random_tile_vector(std::vector<int> & tile_set) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(1, (int)tiles_ids.size());

    for (int & i : tile_set) {
        i = dis(gen);
    }
    return tile_set;
}

#endif
