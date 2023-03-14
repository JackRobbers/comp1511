#include <stdio.h>

void fake_sleep(int cycles) {
    int i = 0;
    while (i < cycles) {
        i++;
    }
}

int main(void) {
    while (1) {
        printf("Welcome to tute 3\n"); 
        fake_sleep(1000000000);
    }
    return 0;
}
