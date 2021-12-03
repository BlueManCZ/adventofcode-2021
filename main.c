#include "solutions/day_01.c"
#include "solutions/day_02.c"
#include "solutions/day_03.c"

int main(void) {
    printf("Advent of code 2021 solutions:\n"
           "\nDay 1:\n"
           "  a) %i\n"
           "  b) %i\n"
           "\nDay 2:\n"
           "  a) %li\n"
           "  b) %li\n"
           "\nDay 3:\n"
           "  a) %li\n"
           "  b) %li\n",
           day1a(), day1b(),
           day2a(), day2b(),
           day3a(), day3b()
    );
}