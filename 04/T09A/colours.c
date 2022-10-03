// functions to interact with colours
// jack robbers, z5263682, 2022.10.04

#include <stdio.h>

struct colour {
    int red;
    int green;
    int blue;
};

enum channel {
    RED,
    GREEN,
    BLUE,
};

int clamp(int value, int min, int max);

struct colour make_colour(int red, int green, int blue);

enum channel get_main_colour(struct colour colour);

struct colour invert_colour(struct colour colour);

int main(void) {
    struct colour red = make_colour(255, 0, 0);

    struct colour not_red = invert_colour(red);

    if (get_main_colour(not_red) == RED) {
        printf("This is mostly red\n");
    } else {
        printf("No longer red\n");
    }
    return 0;
}

// takes a value and moves in inside min and max if it isn't already
int clamp(int value, int min, int max) {
    if (value < min) {
        value = min;
    }
    if (value > max) {
        value = max;
    }
    return value;
}   

// returns a newly made struct colour, with values guaranteed to be within 0-255
struct colour make_colour(int red, int green, int blue) {
    struct colour new;

    new.red = clamp(red, 0, 255);
    new.green = clamp(green, 0, 255);
    new.blue = clamp(blue, 0, 255);
    return new;
}
 
// return the channel with the highest value
enum channel get_main_colour(struct colour colour) {
    enum channel result;

    // some weirdness / non symetric, when main colours has multiple options
    if (colour.red > colour.blue && colour.red > colour.green) {
        result = RED;
    } else if (colour.green > colour.blue && colour.green > colour.red) {
        result = GREEN;
    } else {
        result = BLUE;
    }

    return result;
}

struct colour invert_colour(struct colour colour) {
    struct colour result;

    // result.red = 255 - colour.red;
    // result.green = 255 - colour.green;
    // result.blue = 255 - colour.blue;

    result = make_colour(255 - colour.red, 255 - colour.green, 255 - colour.blue);

    return result;
}