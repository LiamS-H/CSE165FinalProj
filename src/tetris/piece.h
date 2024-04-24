//
// Created by liams on 4/4/2024.
//

#ifndef CSE165FINALPROJ_PIECE_H
#define CSE165FINALPROJ_PIECE_H

#include <vector>
#include <string>
#include <memory>
#include "tileset.h"

//const std::vector<char> piece_ids;
const extern std::vector<char> piece_ids;

class piece {
protected:
    std::vector<std::vector<int>> * board;
    std::vector<std::vector<int>> shape;
    unsigned int height;
    unsigned int width;
    int x;
    int y;
public:
    int tile_id;
    virtual bool rotate();
    bool relative_move(int relative_x, int relative_y);
    [[nodiscard]] bool validate() const;
    [[nodiscard]] bool validate(int x, int y) const;
    [[nodiscard]] unsigned int getHeight() const;
    [[nodiscard]] unsigned int getWidth() const;
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    [[nodiscard]] std::vector<std::vector<int>> board_with_piece() const;
    [[nodiscard]] std::vector<std::vector<int>> blank_board_with_placed_piece() const;
    virtual ~piece();

    friend std::ostream& operator<<(std::ostream& os, const piece& obj);
};

class pieceFactory {
public:
    static std::unique_ptr<piece> createPiece(char type, std::vector<std::vector<int>> * board);
    static std::vector<std::vector<int>> getShape(char type);
};

#endif //CSE165FINALPROJ_PIECE_H
