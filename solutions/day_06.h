long simulateFish(int days, int initialCount) {
    char * line = NULL;
    size_t len = 0;
    FILE * fp = fopen("../inputs/day_06.txt", "r");

    long numbers[initialCount];
    getline(&line, &len, fp);
    split(line, numbers, ',');
    fclose(fp);

    long fish[9] = {0};
    long count = initialCount;

    for (int i = 0; i < initialCount; i++) fish[numbers[i]]++;

    for (int i = 0; i < days; i++) {
        long birth = fish[0];
        for (int j = 1; j < 9; j++) fish[j - 1] = fish[j];
        fish[6] += birth;
        count += fish[8] = birth;
    }

    return count;
}

long day6a() {
    return simulateFish(80, 300);
}

long day6b() {
    return simulateFish(256, 300);
}