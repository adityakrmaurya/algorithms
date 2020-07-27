// Use arrays to develop Sieve of Eratosthenes
// Set 1 for prime 0 for composite number
#include <iostream>
static const int N = 7920;
int main() {
  int a[N];
  for (int i = 0; i < N; i++) {
    a[i] = 1;
  }
  // Leave all the multiples of 2
  for (int i = 3; i < N; i += 2) {
    if (a[i]) {
      for (int j = i; j * i < N; j += 2) {
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
  return 0;
}
