#define COUNT 1000
#define ROOF 2000

long day7a() {
    long numbers[COUNT];
    splitFile("../inputs/day_07.txt", numbers, ',');

    long crabs[ROOF] = {0};
    for (int i = 0; i < COUNT; i++) crabs[numbers[i]]++;

    int median = -1;
    long fuel = 0;
    for (long i = 0; i < (COUNT / 2);) i += crabs[++median];
    for (int i = 0; i < ROOF; i++) fuel += crabs[i] * abs(i - median);

    return fuel;
}

int unroll(int number) {
    int result = 0;
    for (; number > 0; number--) result += number;
    return result;
}

long day7b() {
    long numbers[COUNT];
    splitFile("../inputs/day_07.txt", numbers, ',');

    long crabs[ROOF] = {0};
    long sum = 0;
    long fuel = 0;
    for (int i = 0; i < COUNT; i++) (sum += numbers[i]) && crabs[numbers[i]]++;
    for (int i = 0; i < ROOF; i++) fuel += crabs[i] * unroll(abs(i - (int)sum / COUNT));

    return fuel;
}