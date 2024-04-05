//
// Created by liams on 4/4/2024.
//

#ifndef CSE165FINALPROJ_OBJECT_H
#define CSE165FINALPROJ_OBJECT_H


class graphic {
public:
    virtual void render_frame() const = 0;
    virtual void process_frame() = 0;
};


#endif //CSE165FINALPROJ_OBJECT_H
