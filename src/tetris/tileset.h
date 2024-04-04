//
// Created by liams on 4/3/2024.
//

#ifndef TILESET_H
#define TILESET_H

#include <vector>
#include <map>
#include <string>
#include <stdexcept>
#include <iostream>
#include <random>

const std::vector<int> tiles_ids = {0,1,2,3,4,5,6,7};

std::string color_from_id(int tile_id) {
    std::map<int, std::string> color_map = {
        {0, "#000000"},  // Black (empty cell)
        {1, "#FF0000"},  // Red
        {2, "#00FF00"},  // Green
        {3, "#0000FF"},  // Blue
        {4, "#FFFF00"},  // Yellow
        {5, "#FF00FF"},  // Magenta
        {6, "#00FFFF"},  // Cyan
        {7, "#FFA500"}   // Orange
        // You can add more colors as needed
    };
    try {
        std::string color = color_map.at(tile_id);
        return color;
    } catch (const std::out_of_range& e) {
        std::cerr << "tile_id " << tile_id << "  out of range." << std::endl;
        return "#000000";
    }
}

int random_tile() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(1, (int)tiles_ids.size());

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
