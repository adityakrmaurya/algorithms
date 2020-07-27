// Using Command-line Arguments
#include <iostream>

// takes the max limit from the command line
int main(int argc, char *argv[]) {
  unsigned long N = atoi(argv[1]);
  unsigned long *a = new unsigned long[N]; // allocaes memory in heap
  if (a == 0) {
    std::cout << "Out of Memory" << std::endl;
    return -1;
  }
  for (unsigned long i = 0; i < N; i++) {
    a[i] = 1;
  }
  // Leave all the multiples of 2
  for (unsigned long i = 3; i < N; i += 2) {
    if (a[i]) {
      for (unsigned long j = i; j * i < N; j += 2) {
        a[i * j] = 0;
      }
    }
  }
  std::cout << 2 << " "; // only even prime number
  for (int i = 3; i < N; i += 2) {
    if (a[i]) {
      std::cout << i << " ";
    }
  }
  delete[] a;
  return 0;
}