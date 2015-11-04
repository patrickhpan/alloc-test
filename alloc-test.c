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

int main(int argc, char** argv) {
  if(argc != 3) return 1;
  int trials = atoi(argv[1]);
  size_t size = (size_t) atoi(argv[2]);
  clock_t alloca_start = clock();
  for(int i = 0; i < trials; i++) {
    alloca_test(size);
  }
  clock_t alloca_end = clock();
  printf("Alloca: %i allocations of %zu bytes took %lu clocks.\n", trials, size, alloca_end - alloca_start);
  clock_t malloc_start = clock();
  for(int i = 0; i < trials; i++) {
    malloc_test(size);
  }
  clock_t malloc_end = clock();
  printf("Malloc: %i allocations of %zu bytes took %lu clocks.\n", trials, size, malloc_end - malloc_start);
  printf("Alloca was %.03f times faster than malloc.\n", (double) (malloc_end - malloc_start) / (alloca_end - alloca_start));
  return 0;
}
