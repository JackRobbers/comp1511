// a program for manipulating colours
// jack z5263682

#include <stdio.h>

#define MAX_COLOUR 255

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

int clamp(int value);

struct colour make_colour(int red, int green, int blue);

enum channel get_main_colour(struct colour colour);

struct colour invert_colour(struct colour uninverted);

int main(void) {

    struct colour purple = make_colour(200, 0, 150);

    enum channel main_colour = get_main_colour(invert_colour(purple));

    if (main_colour == RED) {
        printf("mostly red\n");
    } else {
        printf("not red\n");
    }

    return 0;
}

int clamp(int value) {
    if (value < 0) {
        value = 0;
    }
    if (value > MAX_COLOUR) {
        value = MAX_COLOUR;
    }
    return value;
}

struct colour make_colour(int red, int green, int blue) {
    struct colour new;

    new.red = clamp(red);
    new.green = clamp(green);
    new.blue = clamp(blue);

    return new;
}

enum channel get_main_colour(struct colour colour) {
    if (colour.red > colour.blue && colour.red > colour.green) {
        return RED;
    } else if (colour.green > colour.blue && colour.green > colour.red) {
        return GREEN;
    } else {
        return BLUE;
    }
}

struct colour invert_colour(struct colour uninverted) {
    struct colour inverted = make_colour(
        MAX_COLOUR - uninverted.red, 
        MAX_COLOUR - uninverted.green, 
        MAX_COLOUR - uninverted.blue
    );

    // inverted.red = MAX_COLOUR - uninverted.red;
    // inverted.green = MAX_COLOUR - uninverted.green;
    // inverted.blue = MAX_COLOUR - uninverted.blue;

    return inverted;
}
