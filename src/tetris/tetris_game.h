//
// Created by liams on 4/3/2024.
//

#ifndef CSE165FINALPROJ_TETRIS_GAME_H
#define CSE165FINALPROJ_TETRIS_GAME_H
#include <vector>
#include <queue>
#include <chrono>
#include "tileset.h"
#include "piece.h"
#include "../ui/graphic.h"
#include "../ui/game.h"


class tetris_game: public graphic {
protected:
    int tile_size;
    int border_size;
//    int window_height;
//    int window_width;
    int tick_rate;
    void reset_last_tick();
    std::chrono::milliseconds last_tick;
    std::vector<std::vector<int>> board;
    unsigned int board_width;
    unsigned int board_height;
    std::queue<char> piece_queue;
    std::unique_ptr<piece> current_piece;
    std::mt19937 random_seed;
    void render_frame() const override;
    void process_frame() override;
    void populate_queue();
    void new_piece();
    void place();
    int clear_lines();
    void clear_line(int line);
    [[nodiscard]] bool line_is_full(int line) const;
    void draw_tile(int x, int y, int tile_id) const;
    game * game_window;
public:
    tetris_game();
    void play();
    static tetris_game * global_instance;
    static void global_render_callback();
    friend std::ostream& operator<<(std::ostream& os, const tetris_game& obj);
    ~tetris_game();
};


#endif //CSE165FINALPROJ_TETRIS_GAME_H
