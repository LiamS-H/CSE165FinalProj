//
// Created by liams on 4/4/2024.
//

#ifndef CSE165FINALPROJ_PIECE_H
#define CSE165FINALPROJ_PIECE_H

#include <vector>
#include <string>

class piece {
protected:
    void init(int id);
    std::vector<std::vector<int>> * board;
    [[nodiscard]] bool validate() const;
    std::vector<std::vector<int>> shape;
    unsigned int height;
    unsigned int width;
    int x;
    int y;
public:
    int tile_id;
    std::string color;
    [[nodiscard]] virtual bool rotate();
    [[nodiscard]] bool move(int new_x, int new_y);
    unsigned int getHeight() const;
    unsigned int getWidth() const;
    int getX() const;
    int getY() const;
};


#endif //CSE165FINALPROJ_PIECE_H
