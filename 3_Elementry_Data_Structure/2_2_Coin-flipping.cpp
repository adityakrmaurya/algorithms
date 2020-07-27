/**
 * This program runs the experiment M times, taking both N and M from the
 * command line. It uses an array f to keep track of the frequency of occurrence
 * of the outcome "i heads" for 0 <= i <= N, then prints out a histogram of the
 *  result of the experiments, with one asterisk for each 10 occurrences.
 **/
#include <iostream>

bool heads() { return rand() < RAND_MAX / 2; }

int main(int argc, char *argv[]) {
  int cnt, i, j;
  int N = atoi(argv[1]), M = atoi(argv[2]);
  int *f = new int[N + 1];
  // An array of size N = no. of coins
  for (i = 0; i < N; i++)
    f[i] = 0;

  // calculating number of heads for each expirement of given total coins N
  for (i = 0; i < M; i++, f[cnt]++)
    // checking for heads in jth trial
    for (j = 0, cnt = 0; j <= N; j++)
      if (heads())
        cnt++;

  // Printing the observed data
  for (i = 0; i <= N; i++) {
    if (f[i] == 0)
      std::cout << '.';
    for (j = 0; j < f[i]; j += 10)
      std::cout << "*";
    std::cout << std::endl;
  }
  int max_index = 0;
  for (i = 1; i <= N; i++) {
    if (f[i] > f[max_index]) {
      max_index = i;
    }
  }
  std::cout << max_index << std::endl;
  delete[] f;
  return 0;
}