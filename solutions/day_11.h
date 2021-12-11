// --- Day 11: Dumbo Octopus ---

#define SIZE 10
#define LENGTH 100

int countFlashes(long map[SIZE][SIZE]) {
    int count = 0;
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            if (map[y][x] > 9) {
                count++;
                map[y][x] = 0;

                // Don't judge me please...
                if (x != SIZE - 1) {
                    if (y != 0 && map[y - 1][x + 1]) map[y - 1][x + 1]++;          // Top-right
                    if (map[y][x + 1]) map[y][x + 1]++;                            // Right
                    if (y != SIZE - 1 && map[y + 1][x + 1]) map[y + 1][x + 1]++;   // Bottom-right
                }

                if (x != 0) {
                    if (y != 0 && map[y - 1][x - 1]) map[y - 1][x - 1]++;          // Top-left
                    if (map[y][x - 1] != 0) map[y][x - 1]++;                       // Left
                    if (y != SIZE - 1 && map[y + 1][x - 1]) map[y + 1][x - 1]++;   // Bottom-left
                }

                if (y != 0 && map[y - 1][x]) map[y - 1][x]++;                      // Top
                if (y != SIZE - 1 && map[y + 1][x]) map[y + 1][x]++;               // Bottom
            }
        }
    }
    return (count) ? count + countFlashes(map) : count;
}

long day11a() {
    char * line = NULL;
    size_t len = 0;
    FILE * fp = fopen("../inputs/day_11.txt", "r");

    static long map[SIZE][SIZE];

    int i = 0;
    while ((getline(&line, &len, fp)) != -1) {
        split(line, map[i++], '\0');
    }

    int flashes = 0;
    for (int count = 0; count < LENGTH; count++) {
        for (int y = 0; y < SIZE; y++) {
            for (int x = 0; x < SIZE; x++) {
                map[y][x]++;
            }
        }
        flashes += countFlashes(map);
    }

    return flashes;
}

long day11b() {
    char * line = NULL;
    size_t len = 0;
    FILE * fp = fopen("../inputs/day_11.txt", "r");

    static long map[SIZE][SIZE];

    int i = 0;
    while ((getline(&line, &len, fp)) != -1) {
        split(line, map[i++], '\0');
    }

    int count = 0;

    do {
        for (int y = 0; y < SIZE; y++) {
            for (int x = 0; x < SIZE; x++) {
                map[y][x]++;
            }
        }
        count++;
    } while (countFlashes(map) != (SIZE * SIZE));

    return count;
}