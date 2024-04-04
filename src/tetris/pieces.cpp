//
// Created by liams on 4/4/2024.
//

#include <memory>
#include <algorithm>
#include "piece.h"
#include "tileset.h"

class O_piece;

std::vector<char> piece_ids = {
        'O',
};
class O_piece: public piece {
public:
    O_piece() {
        int id = random_tile();
        this->init(id);
        this->width = 2;
        this->height = 2;
        id = this->tile_id;
        this->shape = {{id, id}, {id, id}};
    }
    explicit O_piece(int id) {
        this->init(id);
        this->width = 2;
        this->height = 2;
        this->shape = {{id, id}, {id, id}};
    }
    bool rotate() override {
        return true;
    }
};
class pieceFactory {
public:
    static std::unique_ptr<piece> createPiece(const char type) {
        if (type == 'O') {
            return std::make_unique<O_piece>(0);
        }
        return nullptr;
    }
    static std::vector<char> shuffledPieceIds() {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::vector result = piece_ids;

        std::shuffle(result.begin(), result.end(), gen);

        return result;
    }
};

