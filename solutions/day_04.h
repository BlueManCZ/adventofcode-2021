typedef struct {
    long values[5][5];
} Board;

void split(const char * input, long output[], char delimiter) {
    char buffer[10] = {'\0'};
    int index = 0;
    int count = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == delimiter || input[i] == '\n') {
            if (!i) continue;
            while (input[i] == delimiter) i++;
            output[count++] = strtol(buffer, NULL, 10);
            index = 0;
            memset(buffer, 0, 10 * sizeof(char));
        }
        buffer[index++] = input[i];
    }
}

void loadBoards(Board boards[], FILE * file) {
    char * line = NULL;
    size_t len = 0;

    int boardIndex = -1;
    int rowIndex = 0;

    while ((getline(&line, &len, file)) != -1) {
        if (line[0] == '\n') {
            boardIndex += 1;
            Board newBoard = {0};
            boards[boardIndex] = newBoard;
            rowIndex = 0;
            continue;
        }

        long row[5];
        split(line, row, ' ');
        memcpy(boards[boardIndex].values[rowIndex], row, sizeof row);
        rowIndex++;
    }
}

int checkWin(Board board) {
    for (int x = 0; x < 5; x++) {
        int counterR = 0;
        int counterC = 0;
        for (int y = 0; y < 5; y++) {
            if (board.values[x][y] > -1) counterR++;
            if (board.values[y][x] > -1) counterC++;
        }
        if (counterR > 4) return 1;
        if (counterC > 4) return 1;
    }
    return 0;
}

long calcScore(Board board, Board mask, long number) {
    long score = 0;
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            if (mask.values[x][y] > -1) continue;
            score += board.values[x][y];
        }
    }
    return score * number;
}

long day4a() {
    char * line = NULL;
    size_t len = 0;
    FILE * fp = fopen("../inputs/day_04.txt", "r");

    long numbers[100];
    getline(&line, &len, fp);
    split(line, numbers, ',');

    Board boards[100];
    loadBoards(boards, fp);
    fclose(fp);

    Board boardsMask[100];
    memset(boardsMask, -1, sizeof boardsMask);

    for (int i = 0; numbers[i] > -1; i++) {
        for (int b = 0; b < 100; b++) {
            Board cBoard = boards[b];
            for (int x = 0; x < 5; x++) {
                for (int y = 0; y < 5; y++) {
                    if (cBoard.values[x][y] == numbers[i]) {
                        boardsMask[b].values[x][y] = cBoard.values[x][y];
                        if (checkWin(boardsMask[b])) {
                            return calcScore(cBoard, boardsMask[b], numbers[i]);
                        }
                    }
                }
            }
        }
    }

    return 0;
}

long day4b() {
    char * line = NULL;
    size_t len = 0;
    FILE * fp = fopen("../inputs/day_04.txt", "r");

    long numbers[100];
    getline(&line, &len, fp);
    split(line, numbers, ',');

    Board boards[100];
    loadBoards(boards, fp);
    fclose(fp);

    Board boardsMask[100];
    memset(boardsMask, -1, sizeof boardsMask);

    int winCount = 0;
    int boardStatus[100] = {0};

    for (int i = 0; numbers[i] > -1; i++) {
        for (int b = 0; b < 100; b++) {
            Board cBoard = boards[b];
            for (int x = 0; x < 5; x++) {
                for (int y = 0; y < 5; y++) {
                    if (cBoard.values[x][y] == numbers[i]) {
                        boardsMask[b].values[x][y] = cBoard.values[x][y];
                        if (!boardStatus[b] && checkWin(boardsMask[b])) {
                            boardStatus[b] = 1;
                            if (++winCount == 100) {
                                return calcScore(cBoard, boardsMask[b], numbers[i]);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}