//
// Created by liams on 4/4/2024.
//

#include <memory>
#include <algorithm>
#include "piece.h"
#include "tileset.h"

const std::vector<char> piece_ids = {
        'O',
        'I',
        'S',
        'T',
        'Z',
        'J',
        'L'
};

class O_piece : public piece {
public:
    O_piece(int id, std::vector<std::vector<int>> *board) {
        this->width = 2;
        this->height = 2;
        this->y = 21;
        this->x = 0;

        this->tile_id = id;
        this->shape = {{id, id},
                       {id, id}};
        this->board = board;
    }
};

class I_piece : public piece {
public:
    I_piece(int id, std::vector<std::vector<int>> *board) {
        this->width = 4;
        this->height = 1;
        this->y = 21;
        this->x = 0;

        this->tile_id = id;
        this->shape = {{id, id, id, id}};
        this->board = board;
    }
};

class S_piece : public piece {
public:
    S_piece(int id, std::vector<std::vector<int>> *board) {
        this->width = 3;
        this->height = 2;
        this->y = 21;
        this->x = 0;

        this->tile_id = id;
        this->shape = {{0, id, id},
                       {id, id, 0}};
        this->board = board;
    }
};

class T_piece : public piece {
public:
    T_piece(int id, std::vector<std::vector<int>> *board) {
        this->width = 3;
        this->height = 2;
        this->y = 21;
        this->x = 0;

        this->tile_id = id;
        this->shape = {{0, id, 0},
                       {id, id, id}};
        this->board = board;
    }
};

class Z_piece : public piece {
public:
    Z_piece(int id, std::vector<std::vector<int>> *board) {
        this->width = 3;
        this->height = 2;
        this->y = 21;
        this->x = 0;

        this->tile_id = id;
        this->shape = {{id, id, 0},
                       {0, id, id}};
        this->board = board;
    }
};

class J_piece : public piece {
public:
    J_piece(int id, std::vector<std::vector<int>> *board) {
        this->width = 3;
        this->height = 2;
        this->y = 21;
        this->x = 0;

        this->tile_id = id;
        this->shape = {{id, 0, 0},
                       {id, id, id}};
        this->board = board;
    }
};

class L_piece : public piece {
public:
    L_piece(int id, std::vector<std::vector<int>> *board) {
        this->width = 3;
        this->height = 2;
        this->y = 21;
        this->x = 0;

        this->tile_id = id;
        this->shape = {{0, 0, id},
                       {id, id, id}};
        this->board = board;
    }
};

std::unique_ptr<piece> pieceFactory::createPiece(char type, std::vector<std::vector<int>> * const board) {
    if (type == 'O') {
        return std::make_unique<O_piece>(4, board);
    } else if (type == 'I') {
        return std::make_unique<I_piece>(6, board);
    } else if (type == 'S') {
        return std::make_unique<S_piece>(2, board);
    } else if (type == 'T') {
        return std::make_unique<T_piece>(5, board);
    } else if (type == 'Z') {
        return std::make_unique<Z_piece>(1, board);
    } else if (type == 'J') {
        return std::make_unique<J_piece>(3, board);
    } else if (type == 'L') {
        return std::make_unique<L_piece>(7, board);
    }
    return nullptr;
}

std::vector<std::vector<int>> pieceFactory::getShape(char type) {
    if (type == 'O') {
        return std::vector<std::vector<int>>({{4,4,0,0},{4,4,0,0},});
    } else if (type == 'I') {
        return std::vector<std::vector<int>>({{6,6,6,6},{0,0,0,0},});
    } else if (type == 'S') {
        return std::vector<std::vector<int>>({{0,2,2,0},{2,2,0,0},});
    } else if (type == 'T') {
        return std::vector<std::vector<int>>({{0,5,0,0},{5,5,5,0},});
    } else if (type == 'Z') {
        return std::vector<std::vector<int>>({{1,1,0,0},{0,1,1,0},});
    } else if (type == 'J') {
        return std::vector<std::vector<int>>({{3,0,0,0},{3,3,3,0},});
    } else if (type == 'L') {
        return std::vector<std::vector<int>>({{0,0,7,0},{7,7,7,0},});
    }
    return std::vector<std::vector<int>>({{1}});
}
