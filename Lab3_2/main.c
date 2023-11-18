//#include <stdio.h>
//#include <stdatomic.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define CACHE_SIZE 1000000
//#define CACHE_LINE_SIZE 64
//#define STRIDE (CACHE_LINE_SIZE / sizeof(int))
//
//int main() {
//    // CACHE Misses
//    clock_t begin = clock();
//
//    int cache[CACHE_SIZE];
//    int i, j;
//    int sum = 0;
//
//    for(i = 0; i < CACHE_SIZE; i++){
//        cache[i] = i;
//    }
//
//    for(i = 0; i < CACHE_SIZE; i += STRIDE){
//        for(j = 0; j < STRIDE && (i + j) < CACHE_SIZE; j++){
//            sum += cache[i + j];
//        }
//    }
//
//    clock_t end = clock();
//    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    printf("Work Time with stride : %f\n", time_spent);
//    printf("Sum : %d\n", sum);
//
//    return 0;
//}


#include <stdio.h>
#include <stdatomic.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // CACHE delays
    clock_t begin = clock();

    int cache_size = 1000000;
    int cache[cache_size];
    int i;

    for(i = 0; i < cache_size; i++){
        cache[i] = 0;
    }

    for(i = 0; i < cache_size; i++){
        cache[i]++;
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Work Time with stride : %f\n", time_spent);

    return 0;
}
