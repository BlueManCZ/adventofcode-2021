// --- Day 8: Seven Segment Search ---

void splitString(const char *input, char *output[], char delimiter) {
    char buffer[10] = {'\0'};
    int index = 0;
    int count = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == delimiter || input[i] == '\n') {
            if (!i) continue;
            while (input[i] == delimiter) i++;
            output[count] = (char *) malloc(10);
            memcpy(output[count++], buffer, sizeof buffer);
            index = 0;
            memset(buffer, 0, 10 * sizeof(char));
        }
        buffer[index++] = input[i];
    }
}

int length(char *string) {
    if (!string) return 0;
    int length = 0;
    for (char *p = string; *p; p++) length++;
    return length;
}

void sortString(char *string, int range) {
    int buffer[range];
    memset(buffer, '\0', sizeof buffer);
    for (char *p = string; *p; p++) {
        buffer[*p - 97] += 1;
    }
    int i = 0;
    int index = 0;
    while (i < range) {
        if (buffer[i]--) {
            string[index++] = (char)(i + 97);
        } else {
            i++;
        }
    }
}

int contains(char *string, char *pattern) {
    char *s = string;
    char *p = pattern;
    for (;*s;) *s++ == *p && p++;
    return !*p;
}

int containsChar(char *string, char character) {
    char *s = string;
    for (;*s;) if (*s++ == character) return 1;
    return 0;
}

long day8a() {
    char * line = NULL;
    size_t len = 0;
    FILE * fp = fopen("../inputs/day_08.txt", "r");

    long counter = 0;
    while ((getline(&line, &len, fp)) != -1) {
        char *strings[15];
        splitString(line, strings, ' ');

        for (int i = 11; i < 15; i++) {
            switch (length(strings[i])) {
                case 2: case 3: case 4: case 7: counter++;
            }
        }
    }

    fclose(fp);
    return counter;
}

long day8b() {
    char * line = NULL;
    size_t len = 0;
    FILE * fp = fopen("../inputs/day_08.txt", "r");

    int sum = 0;
    while ((getline(&line, &len, fp)) != -1) {
        char *strings[15];
        splitString(line, strings, ' ');
        for (int i = 0; i < 15; i++) sortString(strings[i], 7);

        char *remaining[10];
        memcpy(remaining, strings, sizeof remaining);

        int n[8] = {};
        n[2] = 1; n[3] = 7; n[4] = 4; n[7] = 8;

        char *numbers[10] = {};
        for (int i = 0; i < 10; i++) {
            char * num = strings[i];
            switch (length(num)) {
                case 2: case 3: case 4: case 7:
                    numbers[n[length(num)]] = num; remaining[i] = 0; break;
            }
        }

        int m[3][4] = {
                {4, 6, 1, 0},
                {5, 6, 3, 9},
                {6, 5, 7, 3}
        };

        int c = 6;
        while (c) {
            for (int i = 0; i < 10; i++) {
                char * num = remaining[i];
                switch (c) {
                    case 6: case 5: case 4:
                        if (length(num) == m[c - 4][1]
                            && contains(num, numbers[m[c - 4][2]])) {
                            numbers[m[c - 4][3]] = num;
                            remaining[i] = 0; c--;
                        } break;
                    case 3:
                        if (length(num) == 6) {
                            numbers[6] = num;
                            remaining[i] = 0; c--;
                        } break;
                    case 2:
                        if (num) {
                            int count = 0;
                            for (char *p = num; *p; p++) {
                                containsChar(numbers[4], *p) && (count += 1);
                            }
                            if (count == 3) {
                                numbers[5] = num;
                                remaining[i] = 0; c--;
                            }
                        } break;
                    default:
                        if (num) {
                            numbers[2] = num;
                            c--;
                        } break;
                }
            }
        }

        for (int i = 11; i < 15; i++) {
            for (int j = 0; j < 10; j++) {
                if (!memcmp(strings[i], numbers[j], 7)) {
                    sum += j * pow(10, 14 - i);
                    break;
                }
            }
        }
    }

    fclose(fp);
    return sum;
}