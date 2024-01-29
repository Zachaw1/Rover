#include "Rover.cpp"
#include <iostream>
#include <string>

int main() {

    Rover rover;

    // Testing
    // rover.move_to_position(3, 0);
    // rover.move_to_position(-3, 0);
    // rover.move_to_position(0, 3);
    // rover.move_to_position(0, -3);

    // rover.move_to_position(3, 3);
    // rover.move_to_position(-3, -3);
    // rover.move_to_position(-3, 3);
    // rover.move_to_position(3, -3);
    
    // Move for assigned exercise
    rover.move_to_position(1, 1);
    rover.move_to_position(-2, -2);
    rover.move_to_position(2, 2);
    rover.move_to_position(-1, -1);
    rover.move_to_position(2, -2);

    return 0;
}