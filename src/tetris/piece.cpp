//
// Created by liams on 4/4/2024.
//

#include "piece.h"
#include "tileset.h"

piece::~piece() {

}



bool piece::validate() const {
    unsigned int board_height = this->board->size();
    unsigned int board_width = this->board[0].size();
//    if (board_height < this->y + this->height) {
//        return false;
//    }
    if (this->y < 0) {
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
            if (this->y+shape_y >= board->size()) continue;
            int board_tile = (*board)[this->y+shape_y][this->x+shape_x];
            if (board_tile == 0) continue;
            return false;
        }
    }
    return true;

}

bool piece::relative_move(int relative_x, int relative_y) {
    int old_x = this->x;
    int old_y = this->y;
    this->x += relative_x;
    this->y += relative_y;
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

std::vector<std::vector<int>> piece::board_with_piece() const {
    std::vector<std::vector<int>> result;
    result = * this->board;
    for (int shape_y=0; shape_y < this->height; shape_y++) {
        for (int shape_x=0; shape_x < this->width; shape_x++) {
            int shape_tile = this->shape[shape_y][shape_x];
            if (shape_tile == 0) continue;
            if (this->y+shape_y >= board->size()) continue;
            result[this->y+shape_y][this->x+shape_x] = shape_tile;
        }
    }
    return result;
}

std::ostream &operator<<(std::ostream &os, const piece &obj) {
    os << "(" << obj.x << ", " << obj.y << ")" << std::endl;
    return os;
}

bool piece::rotate() {
    std::vector<std::vector<int>> result(width, std::vector<int>(height));
    auto old_shape = this->shape;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            result[j][i] = shape[i][j];
        }
    }

    for (int i = 0; i < width / 2; ++i) {
        for (int j = 0; j < height; ++j) {
            std::swap(result[i][j], result[width - i - 1][j]);
        }
    }
    this->shape = result;
    std::swap(this->height, this->width);

    if (!(this->validate())) {
        this->shape = old_shape;
        std::swap(this->height, this->width);
        return false;
    }

    return true;
}
