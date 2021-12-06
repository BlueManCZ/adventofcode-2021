long simulateFish(int days, long count) {
    char * line;
    size_t len = 0;
    FILE * fp = fopen("../inputs/day_06.txt", "r");

    long numbers[count];
    getline(&line, &len, fp);
    split(line, numbers, ',');
    fclose(fp);

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