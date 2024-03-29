#include "Rover.h"
#include <iostream>
#include <string>

//Overloaded constructor that takes arguments for the starting position
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
    x_position += 1;
}

void Rover::move_up(){
    std::cout << "Moving up..." << std::endl;
    y_position += 1;
}

void Rover::move_left(){
    std::cout << "Moving left..." << std::endl;
    x_position -= 1;
}

void Rover::move_down(){
    std::cout << "Moving down..." << std::endl;
    y_position -= 1;
}

void Rover::say_position(){
    std::cout << "I am at position: (" << x_position << ", " << y_position << ")" << std::endl; 
}

// Receives an x and y coordinate to move to, and moves the rover to that position
void Rover::move_to_position(int x, int y){
    // Case that the rover is given an invalid location to move to (not on the grid)
    if (x > 2 || x < -2 || y > 2 || y < -2){
        std::string input;
        std::cout << "Oops, you told me to move to the location: (" << x << ", " << y << ")." << std::endl;
        std::cout << "This location is outside of the grid boundaries! I will stay put until I receive a valid input." << std::endl;
        std::cout << "Would you like to hear a joke instead? (Y/N)" << std::endl;
        std::cin >> input;
        if (input == "Y"){
            std::cout << "How do you organize a space party?" << std::endl;
            std::cout << "You planet!" << std::endl;
        } else {
            std::cout << ":( boring..." << std::endl;
        }
        return;
    }

    std::cout << "=====================================================" << std::endl;
    std::cout << "Moving to position: (" << x << ", " << y << ") from position: (" << x_position << ", " << y_position << ")." << std::endl;

    // Trivial case in which the rover is already positioned at the point passed to the function
    if (x_position == x && y_position == y){
        std::cout << "Oops, I'm already at that position!" << std::endl;
        std::cout << "=====================================================" << std::endl;
        return;
    }
    
    try { // Try travelling right
        // Travel right until x-coordinate reached
        while (x_position < x){
            if (x_position + 1 > 2){
                throw(x_position);
            }
            move_right();
            say_position();
        }
    } 
    catch (int curr_x){
        std::cout << "Couldn't move right. Something went wrong. Current x position: " << curr_x << std::endl;
        if (curr_x == 2){
            std::cout << "I am at the edge of the grid. There is no further I can travel to the right." << std::endl;
        }
        std::cout << "=====================================================" << std::endl;
        return;
    }

    try { // Try travelling left
        // Travel left until x-coordinate reached
        while (x_position > x){
            if (x_position - 1 < -2){
                throw(x_position);
            }
            move_left();
            say_position();
        }
    } 
    catch (int curr_x){
        std::cout << "Couldn't move left. Something went wrong. Current x position: " << curr_x << std::endl;
        if (curr_x == -2){
            std::cout << "I am at the edge of the grid. There is no further I can travel to the left." << std::endl;
        }
        std::cout << "=====================================================" << std::endl;
        return;
    }

    try { // Try travelling up
        // Travel up until y-coordinate reached
        while (y_position < y){
            if (y_position + 1 > 2){
                throw(y_position);
            }
            move_up();
            say_position();
        }
    } 
    catch (int curr_y){
        std::cout << "Couldn't move up. Something went wrong. Current y position: " << curr_y << std::endl;
        if (curr_y == 2){
            std::cout << "I am at the edge of the grid. There is no further I can travel up." << std::endl;
        }
        std::cout << "=====================================================" << std::endl;
        return;
    }

    try { // Try travelling down
        // Travel down until y-coordinate reached
        while (y_position > y){
            if (y_position - 1 < -2){
                throw(y_position);
            }
            move_down();
            say_position();
        }
    } 
    catch (int curr_y){
        std::cout << "Couldn't move down. Something went wrong. Current y position: " << curr_y << std::endl;
        if (curr_y == -2){
            std::cout << "I am at the edge of the grid. There is no further I can travel down." << std::endl;
        }
        std::cout << "=====================================================" << std::endl;
        return;
    }

    if (x_position == x && y_position == y){
        std::cout << "I have reached the desired location." << std::endl;
    }
    std::cout << "=====================================================" << std::endl;

}

// Ask the user where to move next
void Rover::move_more() {
    int new_x;
    int new_y;
    std::string input {"Y"};
    while(input == "Y"){
        std::cout << "Where should I move? Enter x and y coordinates separated by a space:" << std::endl;
        std::cin >> new_x >> new_y;
        move_to_position(new_x, new_y);
        std::cout << "Should I keep moving (Y/N)?" << std::endl;
        std::cin >> input;
    }
    std::cout << "Got it. I'll stay here." << std::endl;
}