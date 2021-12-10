// --- Day 6: Lanternfish ---

void splitFile(char * filename, long output[], char delimiter) {
    char * line;
    size_t len = 0;
    FILE * fp = fopen(filename, "r");
    getline(&line, &len, fp);
    split(line, output, delimiter);
    fclose(fp);
}

long simulateFish(int days, long count) {
    long numbers[count];
    splitFile("../inputs/day_06.txt", numbers, ',');

    long fish[10] = {0};
    for (int i = 0; i < count; i++) fish[numbers[i]]++;

    for (int i = 0; i < days; i++) {
        fish[7] += fish[9] = fish[0];
        count += fish[0];
        for (int j = 1; j < 10; j++) fish[j - 1] = fish[j];
    }

    return count;
}

long day6a() {
    return simulateFish(80, 300);
}

long day6b() {
    return simulateFish(256, 300);
}