// --- Day 1: Sonar Sweep ---

long day1a() {
    char * line = NULL;
    size_t len = 0;
    FILE * fp = fopen("../inputs/day_01.txt", "r");

    long lastLine = 0;
    int counter = -1;

    while ((getline(&line, &len, fp)) != -1) {
        long l = strtol(line, NULL, 10);
        if (l > lastLine) counter++;
        lastLine = l;
    }

    fclose(fp);
    return counter;
}

long day1b() {
    char * line = NULL;
    size_t len = 0;
    FILE * fp = fopen("../inputs/day_01.txt", "r");

    int counter = 0;

    long list[2000];

    while ((getline(&line, &len, fp)) != -1) {
        list[counter++] = strtol(line, NULL, 10);
    }

    int index = 0;
    long lastSum = 0;
    counter = -1;

    while (index + 2 < 2000) {
        long sum = list[index] + list[index + 1] + list[index + 2];
        index++;
        if (sum > lastSum) counter++;
        lastSum = sum;
    }

    fclose(fp);
    return counter;
}