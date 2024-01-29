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
    std::cout << "I am at position: (" << x_position << "," << y_position << ")" << std::endl; 
}