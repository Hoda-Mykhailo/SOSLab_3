#include <stdio.h>
#include <time.h>
    // sequel memory
int main() {
    clock_t begin = clock();
    int cache_size = 1000000;
    int array[cache_size];
    int i;
    int sum = 0;

    for(i = 0; i < cache_size; i++){
        array[i] = i;
    }

    for(i = 0; i < cache_size; i++){
        sum += array[i];
    }

    printf("Sum of Array element = %d\n", sum);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Work Time : %f\n", time_spent);

    return 0;
}
