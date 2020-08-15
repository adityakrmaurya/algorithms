/**
 * Bottom-up heap construction takes linear time
 * ________________________
 *   nodes  |  T(bottom-up)
 * ------------------------
 *    1     |      log n
 *    2     |
 *    .     |        .
 *    .     |        .
 *    .     |        .
 *  <= n/4  |        2
 *  <= n/2  |        1
 * ------------------------
 *
 * T(BuildHeap) <= n/2 * 1 + n/4 * 2 + ... 1 * log n  <= n * sigma i/2^i = 2n
 *
 * Heapsort uses fewer than 2 N lg N comparisons to sort N elements
 *
 * Heap-based selection allows the kth largest of N items to be found in time
 * proportional to N when k is small or close to N, and in time proportional to
 * N log N otherwise
 *
 **/

#include <iostream>
using namespace std;

template <typename T> void exch(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

template <typename T> void fix_down(T pq[], int k, int size) {
  while (2 * k <= size) {
    int j = 2 * k;
    if (j < size && pq[j] < pq[j + 1])
      j++;
    if (!(pq[j] > pq[k]))
      break;
    exch(pq[j], pq[k]);
    k = j;
  }
}

template <typename T> void heapsort(T a[], int l, int r) {
  int k, size = r - l + 1;
  // index zero element of array is 1st element of heap
  T *pq = a + l - 1;
  // while loop exchanges the largest element with the final element in the
  // array and repairs the heap, continuing until the heap is empty. The pointer
  // pq to a[l-1] allows the code to treat the subarray passed to it as an array
  // with the first element at index 1
  for (k = size / 2; k >= 1; k--) {
    fix_down(pq, k, size);
  }
  while (size > 1) {
    exch(pq[1], pq[size]);
    fix_down(pq, 1, --size);
  }
}

int main() {
  char array[10] = {'a', 's', 'o', 'r', 't', 'i', 'n', 'g', 'e', 'x'};
  heapsort(array, 0, 9);
  for (int i = 0; i < 10; i++) {
    cout << array[i] << " ";
  }
  return 0;
}