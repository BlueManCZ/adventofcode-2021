long day2a() {
    char * line = NULL;
    size_t len = 0;
    FILE * fp = fopen("../inputs/day_02.txt", "r");
    ssize_t length;

    long distance = 0;
    long depth = 0;

    while ((length = getline(&line, &len, fp)) != -1) {
        switch (length) {
            case 5: { // Up
                depth -= strtol(line + 3, NULL, 10);
                break;
            }
            case 7: { // Down
                depth += strtol(line + 5, NULL, 10);
                break;
            }
            default: { // Forward
                distance += strtol(line + 8, NULL, 10);
            }
        }
    }

    fclose(fp);
    return depth * distance;
}

long day2b() {
    char * line = NULL;
    size_t len = 0;
    FILE * fp = fopen("../inputs/day_02.txt", "r");
    ssize_t length;

    long distance = 0;
    long depth = 0;
    long aim = 0;

    while ((length = getline(&line, &len, fp)) != -1) {
        switch (length) {
            case 5: { // Up
                aim -= strtol(line + 3, NULL, 10);
                break;
            }
            case 7: { // Down
                aim += strtol(line + 5, NULL, 10);
                break;
            }
            default: { // Forward
                long value = strtol(line + 8, NULL, 10);
                distance += value;
                depth += aim * value;
            }
        }
    }

    fclose(fp);
    return depth * distance;
}