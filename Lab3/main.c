#include <stdio.h>
#include <stdatomic.h>
#include <time.h>

int main() {
    // Atomic
    clock_t begin = clock();
    atomic_int cache;
    atomic_store(&cache, 0);

    int value = atomic_load(&cache);
    for(int i = 1; i<1000000; i++){
        atomic_store(&cache, i);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Work Time : %f\n", time_spent);

    return 0;
}
