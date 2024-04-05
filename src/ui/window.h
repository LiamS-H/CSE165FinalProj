//
// Created by liams on 4/3/2024.
//

#ifndef CSE165FINALPROJ_WINDOW_H
#define CSE165FINALPROJ_WINDOW_H
#include "graphic.h"
#include <vector>


class window: public graphic {
protected:
    int h;
    int w;
    std::vector<graphic *> graphics;

public:
    static window * global_window;
    static void global_render_callback();
    void close();

    void add(graphic * obj);
    void render_frame() const override;

    virtual void display();
    window(int width, int height);
    ~window();
};


#endif //CSE165FINALPROJ_WINDOW_H
