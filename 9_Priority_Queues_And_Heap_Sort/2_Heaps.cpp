/**
 * In a heap, the records are stored in an array such that each key is
 * guaranteed to be larger than the keys at two other specific positions
 *
 * A tree is heap-ordered if the key in each node is larger than or equal to
 * the keys in all of that node's children
 *
 * A heap is a set of nodes with keys arranged in a complete heap-ordered
 * binary tree, represented as an array
 *
 * heapifying = fixing the heap
 **/
#include <iostream>
using namespace std;

// swap function using an extra variable.
template <typename T> void exch(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

// Bottom-up Heapify: node's key becomes larger than that node's parent's key
template <typename T> void fix_up(T array[], int k) {
  // continue to exchange new_node with its parent until we encounter the root
  // or node on the path from new_node to the root that is larger than new_node
  while (k > 1 && array[k / 2] < array[k]) {
    // exchange the parent node with new_node
    exch(array[k], array[k / 2]);
    k = k / 2;
  }
}

// Top-down Heapify: node's key becomes smaller than one or both of that node's
// childrens' keys
template <typename T> void fix_down(T array[], int k, int size) {
  // exchanging the key in the given node with the largest key among that node's
  // children, moving down to that child, and continuing down the tree until
  // reach the bottom or a point where no child has a larger key
  while (2 * k <= size) {
    int j = 2 * k;
    // checks if bottom of heap is reached and which of two child is greater
    if (j < size && array[j] < array[j + 1])
      j++;
    // heap condition is satisfied in the middle
    if (!(array[k] < array[j]))
      break;
    // swaps the elements
    exch(array[k], array[j]);
    k = j;
  }
}

template <class T> class PQ {
private:
  T *pq;
  int size;

public:
  PQ(int capacity) {
    pq = new T[capacity + 1];
    size = 0;
  }
  bool empty() const { return size == 0; }
  // insert requires no more than lg N comparisons and remove the maximum no
  // more than 2lg N comparisons, when performed on an N-item queue
  void insert(T item) {
    // not at position 0 because chlid of 0 is at index 0 0 hence leads to error
    pq[++size] = item;
    fix_up(pq, size);
  }
  T get_max() {
    exch(pq[1], pq[size]);
    fix_down(pq, 1, size - 1);
    return pq[size--];
  }
  void print() {
    for (int i = 1; i <= size; i++) {
      cout << pq[i] << " ";
    }
  }
  ~PQ() { delete[] pq; };
};

// sorting with priority queue:
template <typename T> void pq_sort(T array[], int l, int r) {
  // use insert to put all the elements on the priority queue, and then use
  // getmax to remove them, in decreasing order
  int k;
  PQ<T> pq(r - l + 1);
  for (k = l; k <= r; k++)
    pq.insert(array[k]);
  for (k = r; k >= l; k--)
    array[k] = pq.get_max();
}

int main(void) {
  // The total cost of constructing a heap of size N is less than
  // lg 1 + lg 2 + ... + lg N, which is less than N lg N.
  PQ<char> pq(8);
  pq.insert('a');
  pq.insert('s');
  pq.insert('o');
  pq.insert('r');
  pq.insert('t');
  pq.insert('i');
  pq.insert('n');
  pq.insert('g');
  pq.print();

  int array[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
  pq_sort(array, 0, 9);
  return 0;
}