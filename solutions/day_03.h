#define LEN 12

long day3a() {
    char * line = NULL;
    size_t len = 0;
    FILE * fp = fopen("../inputs/day_03.txt", "r");

    int data[LEN] = {0};
    char gamma[LEN + 1] = {'\0'};
    char epsilon[LEN + 1] = {'\0'};

    while ((getline(&line, &len, fp)) != -1) {
        for (int i = 0; i < LEN; i++) {
            data[i] += (line[i] == '1') ? 1 : -1;
        }
    }

    fclose(fp);

    for (int i = 0; i < LEN; i++) {
        gamma[i] = (data[i] > 1) ? '1' : '0';
        epsilon[i] = (data[i] > 1) ? '0' : '1';
    }

    return strtol(gamma, NULL, 2) * strtol(epsilon, NULL, 2);
}

long day3b() {
    char * line = NULL;
    size_t len = 0;

    char gMask[LEN] = {'\0'};
    char sMask[LEN] = {'\0'};

    long generator, scrubber;

    for (int index = 0; index < LEN; index++) {
        int gCount, sCount, gSkip, sSkip;
        gCount = sCount = 0;

        FILE * fp = fopen("../inputs/day_03.txt", "r");

        while ((getline(&line, &len, fp)) != -1) {
            gSkip = sSkip = 0;

            for (int i = 0; i < index; i++) {
                if (line[i] != gMask[i]) gSkip++;
                if (line[i] != sMask[i]) sSkip++;
            } if (!gSkip) {
                generator = (gCount) ? generator : strtol(line, NULL, 2);
                gCount += (line[index] == '1') ? 1 : -1;
            } if (!sSkip) {
                scrubber = strtol(line, NULL, 2);
                sCount += (line[index] == '1') ? 1 : -1;
            }
        }

        fclose(fp);

        gMask[index] = (gCount >= 0) ? '1' : '0';
        sMask[index] = (sCount >= 0) ? '0' : '1';
    }

    return generator * scrubber;
}