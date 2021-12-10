// --- Day 5: Hydrothermal Venture ---

void parseLine(const char * input, long output[]) {
    char buffer[10] = {'\0'};
    int index = 0;
    int count = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ',' || input[i] == ' ' || input[i] == '-' || input[i] == '>' || input[i] == '\n') {
            while (input[i] == ',' || input[i] == ' ' || input[i] == '-' || input[i] == '>') i++;
            output[count++] = strtol(buffer, NULL, 10);
            index = 0;
            memset(buffer, 0, 10 * sizeof(char));
        }
        buffer[index++] = input[i];
    }
}

long day5a() {
    char * line = NULL;
    size_t len = 0;
    FILE * fp = fopen("../inputs/day_05.txt", "r");

    int field[1000][1000] = {0};
    while ((getline(&line, &len, fp)) != -1) {
        long row[4];
        parseLine(line, row);
        int start, end;
        if (row[0] == row[2]) {
            start = MIN(row[1], row[3]);
            end = MAX(row[1], row[3]);
            for (; start <= end; start++) field[row[0]][start]++;
        } else if (row[1] == row[3]) {
            start = MIN(row[0], row[2]);
            end = MAX(row[0], row[2]);
            for (; start <= end; start++) field[start][row[1]]++;
        }
    }

    fclose(fp);
    int count = 0;
    for (int i = 0; i < sizeof field / sizeof(int); i++) {
        if ((*field)[i] > 1) count++;
    }

    return count;
}

long day5b() {
    char * line = NULL;
    size_t len = 0;
    FILE * fp = fopen("../inputs/day_05.txt", "r");

    int field[1000][1000] = {0};
    while ((getline(&line, &len, fp)) != -1) {
        long row[4];
        parseLine(line, row);
        long x1, x2, y1, y2;
        if (row[0] == row[2]) {
            x1 = MIN(row[1], row[3]);
            x2 = MAX(row[1], row[3]);
            for (; x1 <= x2; x1++) field[row[0]][x1]++;
        } else if (row[1] == row[3]) {
            x1 = MIN(row[0], row[2]);
            x2 = MAX(row[0], row[2]);
            for (; x1 <= x2; x1++) field[x1][row[1]]++;
        } else {
            x1 = row[0]; x2 = row[2];
            y1 = row[1]; y2 = row[3];
            if (row[0] > row[2]) {
                x1 = row[2]; x2 = row[0];
                y1 = row[3]; y2 = row[1];
            }
            int dir = (y1 < y2) ? 1 : -1;
            while (x1 <= x2) {
                field[x1++][y1]++;
                y1 += dir;
            }
        }
    }

    fclose(fp);
    int count = 0;
    for (int i = 0; i < sizeof field / sizeof(int); i++) {
        if ((*field)[i] > 1) count++;
    }

    return count;
}