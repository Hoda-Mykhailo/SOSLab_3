#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CACHE_LINE_SIZE 100
        // Random memory
int main() {
    clock_t begin = clock();
    int *cache;
    int i, j;
    int size = 1000000;

    cache = (int*) malloc(size * sizeof(int));
    srand(time(NULL));
    for(i = 0; i < size; i++){
        cache[i] = rand();
    }

    for(i = 0; i < size; i++){
        j = rand() % size;
        int temp = cache[i];
        cache[i] = cache[j];
        cache[j] = temp;
    }

    for(i = 0; i < size; i+= CACHE_LINE_SIZE){
        printf("%d\n", cache[i]);
    }
    free(cache);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Work Time with stride : %f\n", time_spent);

    return 0;
}
