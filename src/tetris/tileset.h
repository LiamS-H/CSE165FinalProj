//
// Created by liams on 4/3/2024.
//

#ifndef TILESET_H
#define TILESET_H

#include <vector>
#include <map>
#include <stdexcept>
#include <iostream>
#include <random>

const std::vector<int> tiles_ids;

struct Color{
public:
    float r;
    float g;
    float b;
    Color(float red, float green, float blue);
};

Color color_from_id(int tile_id);

int random_tile();

std::vector<int> random_tile_vector(std::vector<int> & tile_set);

#endif
