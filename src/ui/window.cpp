//
// Created by liams on 4/3/2024.
//

#include <iostream>
#include "window.h"
#include "graphic.h"
#include "../../freeglut/include/GL/freeglut.h"
#include "../../freeglut/include/GL/freeglut_ext.h"
#include "../../freeglut/include/GL/freeglut_std.h"
#include "../../freeglut/include/GL/glut.h"


window::window(int width, int height ) {
    this->h = height;
    this->w = width;
}

window * window::global_window = nullptr;

void window::global_render_callback() {
    window::global_window->render_frame();
}

void window::display() {
    window::global_window = this;
    glutInitWindowSize(this->w, this->h); // Set window size
    glutInitWindowPosition(100, 100); // Set window position
    glutCreateWindow("CSE165Proj");
    glOrtho(0, this->w, 0, this->h, 0, 1);
    glutDisplayFunc(window::global_render_callback);
    glutMainLoop();
}

void window::add(graphic * obj) {
    this->graphics.push_back(obj);
}

void window::render_frame() const {
    for (graphic * obj: this->graphics) {
        obj->render_frame();
    }
}

window::~window() {
    for (graphic * obj: this->graphics) {
        delete obj;
    }
}

void window::close() {
    std::cout << "exiting" << std::endl;
    exit(EXIT_SUCCESS);
}
