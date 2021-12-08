#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>

#include "solutions/all.h"

int main(void) {
    printf("Advent of code 2021 solutions:\n");
    for (int counter = 0; counter < S_COUNT; counter += 2) {
        int day = counter / 2 + 1;
        printf("\nDay %i:\n"
               "  a) %li\n"
               "  b) %li\n",
               day, (*solutions[counter])(), (*solutions[counter + 1])());
    }
}
