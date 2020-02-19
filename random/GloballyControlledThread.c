#define NUM_THREADS 10
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int* gIndex;
unsigned long* divided;
unsigned long long** result;

void* MyFunc(void* a) {
    int lIndex = (int)*gIndex;
    ++(*gIndex);
    //printf("gIndex: %d\n", *gIndex);
    unsigned long long endBound = (lIndex -1) * (*divided) + (*divided) + 1;
    unsigned long long startBound = (lIndex -1) * (*divided) + 1;
    //printf("max for this thread: %lu\n", endBound);
    for(unsigned long long i = startBound ; i < endBound; ++i) {
        (*result[lIndex - 1]) += i;
        //printf("Thread # %lu, i: %lu, value: %llu\n", lIndex, i, *result[lIndex - 1]);
    }
    
}

/*
 *   Not a good thing to do, but wanted to write a set of threads that were controlled through the 
 *   global scope rather than handing in a struct with the required information
 *   For some reason fails when count = MAX unsigned long; Guessing it has something to do with rolling over a value somewhere
 */
int main() {
    unsigned long count = 100120; //4294967295;
    unsigned long long expected = count * (count + 1) / 2;
    unsigned long long actual = 0;
    printf("Expected: %llu\n", expected);

    divided = (unsigned long*) malloc(sizeof(unsigned long));
    *divided = count/NUM_THREADS;
    printf("Divided: %lu\n", *divided);
    pthread_t** threadHolder;
    threadHolder = (pthread_t**) malloc( sizeof(pthread_t*) * NUM_THREADS);

    result = (unsigned long long**) malloc(sizeof(unsigned long long*) * NUM_THREADS);
    for(int i = 0; i < NUM_THREADS; ++i) {
        result[i] = (unsigned long long*) malloc(sizeof(unsigned long long));
        threadHolder[i] = (pthread_t*) malloc(sizeof(pthread_t));
    }

    gIndex = (int*) malloc(sizeof(int));
    *gIndex = 1;
        
    for(int i=0; i < NUM_THREADS; ++i) {        
        pthread_create(threadHolder[i], NULL, MyFunc, NULL);
    }
    for(int i=0; i< NUM_THREADS; ++i) {
        pthread_join(*threadHolder[i], NULL);
    }
    for(int i = 0; i < NUM_THREADS; ++i) {
        actual += *result[i];
        free(result[i]);
        free(threadHolder[i]);
    }
    printf("Actual:   %lld\n", actual);
    free(result);
    free(threadHolder);
    free(gIndex);
    free(divided);
    return 0;
}
