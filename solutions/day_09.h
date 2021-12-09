#define H_W 100
#define H_H 100

long MIN4(long a, long b, long c, long d) {
    return MIN(MIN(a, b), MIN(c, d));
}

long day9a() {
    char * line = NULL;
    size_t len = 0;
    FILE * fp = fopen("../inputs/day_09.txt", "r");

    long hMap[H_H][H_W];

    int i = 0;
    while ((getline(&line, &len, fp)) != -1) {
        split(line, hMap[i++], '\0');
    }

    fclose(fp);
    long result = 0;
    for (int y = 0; y < H_H; y++) {
        for (int x = 0; x < H_W; x++) {
            long v = hMap[y][x];
            if (v < MIN4((y == 0) ? v + 1 : hMap[y - 1][x],       // Top
                         (x == H_W - 1) ? v + 1 : hMap[y][x + 1], // Right
                         (y == H_H - 1) ? v + 1 : hMap[y + 1][x], // Bottom
                         (x == 0) ? v + 1 : hMap[y][x - 1]))      // Left
                result += v + 1;
        }
    }

    return result;
}

long calcSizeOfBasin(long hMapMask[H_H][H_W], int x, int y) {
    if (hMapMask[y][x] == 9) return 0;
    hMapMask[y][x] = 9;
    return 1 + ((y == 0) ? 0 : calcSizeOfBasin(hMapMask, x, y - 1)) + // Top
        ((x == H_W - 1) ? 0 : calcSizeOfBasin(hMapMask, x + 1, y)) +  // Right
        ((y == H_H - 1) ? 0 : calcSizeOfBasin(hMapMask, x, y + 1)) +  // Bottom
        ((x == 0) ? 0 : calcSizeOfBasin(hMapMask, x - 1, y));         // Left
}

long day9b() {
    char * line = NULL;
    size_t len = 0;
    FILE * fp = fopen("../inputs/day_09.txt", "r");

    static long hMap[H_H][H_W];

    int i = 0;
    while ((getline(&line, &len, fp)) != -1) {
        split(line, hMap[i++], '\0');
    }

    static long hMapMask[H_H][H_W];
    memcpy(hMapMask, hMap, sizeof hMap);

    long basins[H_H * H_W] = {};

    fclose(fp);

    for (int y = 0; y < H_H; y++) {
        for (int x = 0; x < H_W; x++) {
            long size = calcSizeOfBasin(hMapMask, x, y);
            basins[size]++;
        }
    }

    int result = 0;
    int index = H_H * H_W - 1;
    for (int c = 0; c < 3; index--) {
        while (basins[index]-- > 0) {
            result = (result) ? result * index : index;
            if (c++ > 2) break;
        }
    }

    return result;
}