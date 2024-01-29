#ifndef _ROVER_H_
#define _ROVER_H_

#include <iostream>

class Rover {
private:
    int x_position;
    int y_position;
public:
    Rover(int x_pos, int y_pos);
    Rover();

    void set_x_position(const int &x);
    int get_x_position() const;
    void set_y_position(const int &y);
    int get_y_position() const;

    void move_right();
    void move_up();
    void move_left();
    void move_down();
    void say_position();
};
#endif