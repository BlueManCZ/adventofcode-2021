#include "day_01.h"
#include "day_02.h"
#include "day_03.h"
#include "day_04.h"
#include "day_05.h"
#include "day_06.h"
#include "day_07.h"
#include "day_08.h"
#include "day_09.h"
#include "day_10.h"
#include "day_11.h"

#define S_COUNT (11 * 2)

long (*solutions[S_COUNT])() = {
        day1a, day1b,
        day2a, day2b,
        day3a, day3b,
        day4a, day4b,
        day5a, day5b,
        day6a, day6b,
        day7a, day7b,
        day8a, day8b,
        day9a, day9b,
        day10a, day10b,
        day11a, day11b
};