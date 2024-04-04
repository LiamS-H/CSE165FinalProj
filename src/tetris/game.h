//
// Created by liams on 4/3/2024.
//

#ifndef CSE165FINALPROJ_GAME_H
#define CSE165FINALPROJ_GAME_H
#include <vector>
#include "tileset.h"
#include "piece.h"

class game {
private:
    std::vector<std::vector<int>> board;
    piece current_piece;
public:
    game() {
        this->board = std::vector<std::vector<int>>(20, std::vector<int>(0, 10));
    }
    void render() {

    }
};


#endif //CSE165FINALPROJ_GAME_H
