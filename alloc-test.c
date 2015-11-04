#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void alloca_test(size_t size) {
  void* test = alloca(size);
  (void) test;
}

void malloc_test(size_t size) {
  void* test = malloc(size);
  free(test);
}

void calloc_test(size_t size) {
  void* test = calloc(size, 1);
  free(test);
}

int main(int argc, char** argv) {
  if (argc != 3) return 1;
  int trials = atoi(argv[1]);
  size_t size = (size_t) atoi(argv[2]);

  clock_t alloca_start = clock();
  for (int i = 0; i < trials; i++) {
    alloca_test(size);
  }
  clock_t alloca_end = clock();
  printf("alloca: %i allocations of %zu bytes took %lu clocks.\n", trials, size, alloca_end - alloca_start);

  clock_t malloc_start = clock();
  for (int i = 0; i < trials; i++) {
    malloc_test(size);
  }
  clock_t malloc_end = clock();
  printf("malloc: %i allocations of %zu bytes took %lu clocks.\n", trials, size, malloc_end - malloc_start);

  clock_t calloc_start = clock();
  for (int i = 0; i < trials; i++) {
    calloc_test(size);
  }
  clock_t calloc_end = clock();
  printf("calloc: %i allocations of %zu bytes took %lu clocks.\n", trials, size, calloc_end - calloc_start);

  printf("alloca was \e[0;32m%.03f\e[0;0m times faster than malloc and \e[0;32m%.03f\e[0;0m times faster than calloc.\n", (double) (malloc_end - malloc_start) / (alloca_end - alloca_start), (double) (calloc_end - calloc_start) / (alloca_end - alloca_start));

  return 0;
}
