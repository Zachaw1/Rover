#include "Rover.h"
#include <iostream>

//Overloaded constructor that takes arguments for the starting position:
Rover::Rover(int x_pos, int y_pos) : x_position {x_pos}, y_position {y_pos} {
    std::cout << "Hello. I am your Rover." << std::endl;
    std::cout << "I am starting at position: (" << x_position << "," << y_position << ")" << std::endl; 
}

Rover::Rover() : Rover {0, 0} { //Delegate trivial case of starting at (0, 0) to overloaded constructor
}

void Rover::set_x_position(const int &x){
    x_position = x;
}

int Rover::get_x_position() const {
    return x_position;
}

void Rover::set_y_position(const int &y){
    y_position = y;
}

int Rover::get_y_position() const {
    return y_position;
}

void Rover::move_right(){
    std::cout << "Moving right..." << std::endl;
    try{
        if (x_position + 1 > 2){
            throw(x_position);
        }
        x_position += 1;
    }
    catch (int curr_x){
        std::cout << "Couldn't move right. Something went wrong. Current x position: " << curr_x << std::endl;
        if (curr_x == 2){
            std::cout << "I am at the edge of the grid. There is no further I can travel to the right." << std::endl;
        }
    }
}

void Rover::move_up(){
    std::cout << "Moving up..." << std::endl;
    try{
        if (y_position + 1 > 2){
            throw(y_position);
        }
        y_position += 1;
    }
    catch (int curr_y){
        std::cout << "Couldn't move up. Something went wrong. Current y position: " << curr_y << std::endl;
        if (curr_y == 2){
            std::cout << "I am at the edge of the grid. There is no further I can travel up." << std::endl;
        }
    }
}

void Rover::move_left(){
    std::cout << "Moving left..." << std::endl;
    try{
        if (x_position - 1 < -2){
            throw(x_position);
        }
        x_position -= 1;
    }
    catch (int curr_x){
        std::cout << "Couldn't move left. Something went wrong. Current x position: " << curr_x << std::endl;
        if (curr_x == -2){
            std::cout << "I am at the edge of the grid. There is no further I can travel to the left." << std::endl;
        }
    }
}

void Rover::move_down(){
    std::cout << "Moving down..." << std::endl;
    try{
        if (y_position - 1 < -2){
            throw(y_position);
        }
        y_position -= 1;
    }
    catch (int curr_y){
        std::cout << "Couldn't move down. Something went wrong. Current y position: " << curr_y << std::endl;
        if (curr_y == -2){
            std::cout << "I am at the edge of the grid. There is no further I can travel down." << std::endl;
        }
    }
}

void Rover::say_position(){
    std::cout << "I am at position: (" << x_position << ", " << y_position << ")" << std::endl; 
}

// Receives an x and y coordinate to move to, and moves the rover to that position
void Rover::move_to_position(int x, int y){
    std::cout << "=====================================================" << std::endl;
    std::cout << "Moving to position: (" << x << ", " << y << ") from position: (" << x_position << ", " << y_position << ")." << std::endl;

    // Trivial case in which the rover is already positioned at the point passed to the function:
    if (x_position == x && y_position == y){
        std::cout << "Oops, I'm already at that position!" << std::endl;
        return;
    }
    
    // Travel right until x-coordinate reached:
    while (x_position < x){
        move_right();
        say_position();
    }
    // Travel left until x-coordinate reached:
    while (x_position > x){
        move_left();
        say_position();
    }
    // Travel up until y-coordinate reached:
    while (y_position < y){
        move_up();
        say_position();
    }
    // Travel down until y-coordinate reached:
    while (y_position > y){
        move_down();
        say_position();
    }

    std::cout << "I have reached the desired location." << std::endl;
    std::cout << "=====================================================" << std::endl;

}