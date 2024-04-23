//
// Created by liams on 4/4/2024.
//

#include "game.h"
#include "graphic.h"
#include "../../freeglut/include/GL/freeglut.h"
#include "../../freeglut/include/GL/freeglut_ext.h"
#include "../../freeglut/include/GL/freeglut_std.h"
#include "../../freeglut/include/GL/glut.h"

game::game(int width, int height) : window(width, height){}

game * game::global_window = nullptr;

void game::display() {
    game::global_window = this;
    glutInitWindowSize(this->w, this->h); // Set window size
    glutInitWindowPosition(100, 100); // Set window position
    glutInitDisplayMode(GLUT_DOUBLE);
    glutCreateWindow("CSE165Proj");
    glOrtho(0, this->w, 0, this->h, 0, 1);
    glutDisplayFunc(game::global_render_callback);
    glutIdleFunc(game::global_process_callback);
//    glutIdleFunc(game::)
    glutKeyboardFunc(game::global_keyboard_callback);
    glutKeyboardUpFunc(game::global_keyboard_up_callback);
    glutMainLoop();
}

void game::process_frame() {
    for (graphic * obj: this->graphics) {
        obj->process_frame();
    }
    glutPostRedisplay();
}

std::set<unsigned char> game::get_keys_down() {
    return this->keys_down;
}

bool game::is_key_down(unsigned char key) {
    return this->keys_down.find(key) != this->keys_down.end();
}

void game::keyboard(unsigned char key, int x, int y) {
    this->keys_down.insert(key);
}

void game::keyboard_up(unsigned char key, int x, int y) {
    this->keys_down.erase(key);
}

void game::global_keyboard_callback(unsigned char key, int x, int y) {
    if (key == '\x1B') exit(EXIT_SUCCESS);
    game::global_window->keyboard(key, x, y);
}

void game::global_keyboard_up_callback(unsigned char key, int x, int y) {
    game::global_window->keyboard_up(key, x, y);
}

void game::global_render_callback() {
    game::global_window->render_frame();
}

void game::global_process_callback() {
    game::global_window->process_frame();
}