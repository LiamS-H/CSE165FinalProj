//
// Created by liams on 4/4/2024.
//

#ifndef CSE165FINALPROJ_GAME_H
#define CSE165FINALPROJ_GAME_H

#include "window.h"
#include <set>

class game: public window {
private:
    void keyboard(unsigned char key, int x, int y);
    void keyboard_up(unsigned char key, int x, int y);
public:
    std::set<unsigned char> keys_down;
    void process_frame() override;
    void display() override;
    std::set<unsigned char> get_keys_down();
    bool is_key_down(unsigned char key);
    static game * global_window;
    static void global_render_callback();
    static void global_process_callback();
    static void global_keyboard_callback(unsigned char key, int x, int y);
    static void global_keyboard_up_callback(unsigned char key, int x, int y);
    game(int width, int height);
};


#endif //CSE165FINALPROJ_GAME_H
