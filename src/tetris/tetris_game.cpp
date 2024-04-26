//
// Created by liams on 4/3/2024.
//

#include "tetris_game.h"
#include <random>
#include <algorithm>
#include <chrono>
#include "../../freeglut/include/GL/freeglut.h"
#include "../../freeglut/include/GL/freeglut_ext.h"
#include "../../freeglut/include/GL/freeglut_std.h"
#include "../../freeglut/include/GL/glut.h"

#include "../ui/game.h"
#include "../ui/graphic.h"

tetris_game * tetris_game::global_instance = nullptr;

tetris_game::tetris_game() {
    this->tile_size = 40;
    this->border_size = 10;

    this->board_width = 10;
    this->board_height = 20;
    this->board = std::vector<std::vector<int>>(this->board_height+4, std::vector<int>(this->board_width, 0));

    int ui_width = 80;

    this->window_height = this->border_size * 2 + this->board_height * this->tile_size;

    this->window_width = this->border_size * 2 + this->board_width * this->tile_size;
    if (ui_width > 0) {
        this->window_width += ui_width + 2*border_size;
    }

    this->game_window = new game(this->window_width, this->window_height);
    this->game_window->add(this);
    this->tick_rate = 1000;


//    for (auto & row : this->board) {
//        for (auto & tile : row) {
//            tile = random_tile();
//        }
//    }
//    std::cout << *this;

    std::random_device rd;
    this->random_seed = std::mt19937 (rd());
    this->last_tick = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    this->new_piece();
    tetris_game::global_instance = this;
}

tetris_game::~tetris_game() {
    delete this->game_window;
}

void tetris_game::new_piece() {
    while (this->piece_queue.size() < piece_ids.size()) {
        this->populate_queue();
    }
    char piece_id = this->piece_queue.front();
    this->piece_queue.pop_front();
    this->current_piece = pieceFactory::createPiece(piece_id, &this->board);
    if (!(this->current_piece->relative_move(0,-1))) {
        this->game_window->close();
    }
}

void tetris_game::populate_queue() {
    std::vector result = piece_ids;

    std::shuffle(result.begin(), result.end(), this->random_seed);

    for (const auto &tile_id : result ) {
        this->piece_queue.push_back(tile_id);
    }
}

void tetris_game::draw_hud() const {
    int half_border =  (int) this->border_size / 2;
    int game_width = this->board_width * this->tile_size + 2 * this->border_size;
    int game_height = this->board_height * this->tile_size+ 2 * this->border_size;
    int hud_width = this->window_width - game_width;
    glBegin(GL_LINE_LOOP);
    glColor3f(1,1,1);
    glVertex2i(half_border, half_border);
    glVertex2i( game_width - half_border, half_border);
    glVertex2i(game_width - half_border, game_height - half_border);
    glVertex2i(half_border, game_height - half_border);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(1,1,1);
    glVertex2i(game_width + half_border, window_height - hud_width + half_border);
    glVertex2i(game_width + hud_width - half_border, window_height - hud_width + half_border);
    glVertex2i(game_width + hud_width - half_border, window_height - half_border);
    glVertex2i(game_width + half_border, window_height - half_border);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(1,1,1);
    glVertex2i(game_width + half_border, half_border);
    glVertex2i(game_width + hud_width - half_border, half_border);
    glVertex2i(game_width + hud_width - half_border, window_height - hud_width - half_border);
    glVertex2i(game_width + half_border, window_height - hud_width - half_border);
    glEnd();
    int y = window_height - hud_width - border_size - 20;
    int count =0;
    for (auto piece : this->piece_queue) {
        count ++;
        if (count >5) break;
        auto shape = pieceFactory::getShape(piece);
        y -= 20;
        for (const auto& row : shape) {
            int x = game_width + border_size + 10;
            for (auto ele: row) {
                x+=10;
                if (ele == 0) continue;
                Color color = color_from_id(ele);
                glBegin(GL_QUADS);
                glColor3f(color.r, color.g, color.b);
                glVertex2i(x, y);
                glVertex2i(x + 10, y);
                glVertex2i(x + 10, y + 10);
                glVertex2i(x, y + 10);
                glEnd();
            }
            y += 10;
        }
        y -= 30;

    }
}

void tetris_game::draw_tile(int x, int y, int tile_id) const {
    int rendered_x = (int) (this->border_size + (x) * this->tile_size);
    int rendered_y = (int) (this->border_size + (y) * this->tile_size);
    glBegin(GL_QUADS);
    glVertex2i(rendered_x, rendered_y);
    glVertex2i(rendered_x + this->tile_size, rendered_y);
    glVertex2i(rendered_x + this->tile_size, rendered_y + this->tile_size);
    glVertex2i(rendered_x, rendered_y + this->tile_size);
    glEnd();
}

void tetris_game::render_frame() const {
//    std::cout << "Tetris Rendering Frame" << std::endl;
    glClear(GL_COLOR_BUFFER_BIT);

    this->draw_hud();

    const auto display_board = this->current_piece->board_with_piece();
    const auto placed_piece_board = this->current_piece->blank_board_with_placed_piece();

    for (int y=0;y<this->board_height;y++) {
        for (int x=0;x<this->board_width;x++) {
            int tile_id = placed_piece_board[y][x];
            if (tile_id==0) continue;
            Color color = color_from_id(tile_id);
            glColor3f(color.r * 0.5, color.g * 0.5, color.b * 0.5);
            draw_tile(x, y, tile_id);
        }
    }

    for (int y=0;y<this->board_height;y++) {
        for (int x=0;x<this->board_width;x++) {
            int tile_id = display_board[y][x];
            if (tile_id==0) continue;
            Color color = color_from_id(tile_id);
            glColor3f(color.r, color.g, color.b);
            draw_tile(x, y, tile_id);
        }
    }

    glutSwapBuffers();
    glFlush();
}

void tetris_game::process_frame() {

    auto current_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    if (current_time - last_tick >= std::chrono::milliseconds(tick_rate)) {
        game_window->keys_down.insert('s');
        last_tick = current_time;
    }

    if (this->game_window->is_key_down('s')) {
        if (!this->current_piece->relative_move(0, -1)) {
            this->place();
        };
        this->reset_last_tick();
        this->game_window->keys_down.erase('s');
    }
    if (this->game_window->is_key_down('a')) {
        this->current_piece->relative_move(-1, 0);
        this->game_window->keys_down.erase('a');
    }
    if (this->game_window->is_key_down('d')) {
        this->current_piece->relative_move(1, 0);
        this->game_window->keys_down.erase('d');
    }
    if (this->game_window->is_key_down('w')) {
        this->current_piece->rotate();
        this->game_window->keys_down.erase('w');
    }
    if (this->game_window->is_key_down(' ')) {
        this->place();
        this->game_window->keys_down.erase(' ');
    }
}

void tetris_game::global_render_callback() {
    tetris_game::global_instance->render_frame();
}

void tetris_game::play() {
    this->game_window->display();
}

std::ostream & operator<<(std::ostream& os, const tetris_game& game) {
    for (auto const& row : game.board) {
        for (auto tile : row ) {
            os << tile;
        }
        os << std::endl;
    }
    return os;
}

void tetris_game::place() {
    while (this->current_piece->relative_move(0, -1)) {}
    this->board = this->current_piece->board_with_piece();
    this->clear_lines();
    this->new_piece();
    this->reset_last_tick();
}

bool tetris_game::line_is_full(int line) const {
    for (const auto & ele : this->board[line]) {
        if (ele == 0) return false;
    }
    return true;
}

void tetris_game::clear_line(int line) {
    for (int i = line; i < this->board_height - 1; ++i) {
        for (int j = 0; j < this->board_width; ++j) {
            this->board[i][j] = this->board[i + 1][j];
        }
    }
    for (int j = 0; j < this->board_width; ++j) {
        this->board[this->board_height - 1][j] = 0;
    }
}

int tetris_game::clear_lines() {
    int lines = 0;
    for (int line = 0; line < this->board_height; ++line) {
        if (!(this->line_is_full(line))) continue;
        this->clear_line(line);
        line--;
        lines++;
    }
    return lines;
}

void tetris_game::reset_last_tick() {
    auto current_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    this->last_tick = current_time;
}