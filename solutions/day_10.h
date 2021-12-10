// --- Day 10: Syntax Scoring ---

#define L_MAX 110
#define C_MAX 90

long day10a() {
    char * line = NULL;
    size_t len = 0;
    FILE * fp = fopen("../inputs/day_10.txt", "r");

    int values[8] = {')', 3, ']', 57, '}', 1197, '>', 25137};
    int score = 0;

    while ((getline(&line, &len, fp)) != -1) {
        char data[L_MAX] = {};
        int index = 0;
        int exit = 0;
        for (char *p = line; *p; p++) {
            if (exit) break;
            if (*p == '\n') continue;
            switch (*p) {
                case '(': case '[': case '{': case '<': {
                    data[index++] = *p;
                    break;
                } default: {
                    if ((data[--index] + 2) == *p || (data[index] + 1) == *p) continue;
                    exit = 1;
                    for (int i = 0; i < 8; i++) {
                        if (values[i] == *p) {
                            score += values[i + 1];
                            break;
                        }
                    }
                }
            }
        }
    }

    return score;
}

void bubbleSort(long a[], long n) {
    long i, j, tmp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

long day10b() {
    char * line = NULL;
    size_t len = 0;
    FILE * fp = fopen("../inputs/day_10.txt", "r");

    int values[4] = {')', ']', '}', '>'};
    long scores[C_MAX] = {};
    int count = 0;

    while ((getline(&line, &len, fp)) != -1) {
        char data[L_MAX] = {};
        int index = 0;
        int exit = 0;
        for (char *p = line; *p; p++) {
            if (*p == '\n') continue;
            switch (*p) {
                case '(': case '[': case '{': case '<': {
                    data[index++] = *p;
                    break;
                } default: {
                    if ((data[--index] + 2) == *p || (data[index] + 1) == *p) continue;
                    exit = 1;
                }
            }
            if (exit) break;
        }
        if (!exit) {
            long score = 0;
            for (index--; index >= 0; index--) {
                for (int i = 0; i < 4; i++) {
                    if (values[i] == data[index] + 2 || values[i] == data[index] + 1) {
                        score = score * 5 + i + 1;
                        break;
                    }
                }
            }
            scores[count++] = score;
        }
    }

    bubbleSort(scores, count);
    return scores[count / 2];
}