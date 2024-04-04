//
// Created by liams on 4/4/2024.
//

#include "piece.h"
#include "tileset.h"

void piece::init(int id) {
    if (id == 0) {
        this->tile_id = random_tile();
    } else {
        this->tile_id = id;
    }

    this->color = color_from_id(this->tile_id);

}

bool piece::validate() const {
    unsigned int board_height = this->board->size();
    unsigned int board_width = this->board[0].size();
    if (board_height < this->y + this->height) {
        return false;
    }
    if (board_width < this->x + this->width) {
        return false;
    }
    if (this->x < 0) {
        return false;
    }
    for (int shape_y=0; shape_y < this->height; shape_y++) {
        for (int shape_x=0; shape_x < this->width; shape_x++) {
            int shape_tile = this->shape[shape_y][shape_x];
            if (shape_tile == 0) continue;
            int board_tile = (*board)[this->y+shape_y][this->x+shape_x];
            if (board_tile == 0) continue;
            return false;
        }
    }
    return true;

}

bool piece::move(int new_x, int new_y) {
    int old_x = this->x;
    int old_y = this->y;
    this->x = new_x;
    this->y = new_y;
    if (!this->validate()) {
        this->x = old_x;
        this->y = old_y;
        return false;
    }
    return true;

}
unsigned int piece::getHeight() const {
    return this->height;
}
unsigned int piece::getWidth() const {
    return this->width;
}
int piece::getX() const {
    return this->x;
}
int piece::getY() const {
    return this->y;
}