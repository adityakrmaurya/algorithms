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

// Bottom-up Heapify
template <typename T> void fixUp(T array[], int k) {
  // continue to exchange new_node with its parent until we encounter the root
  // or node on the path from new_node to the root that is larger than new_node
  while (k > 1 && a[k / 2] < a[k]) {
    // exchange the parent node with new_node
    T temp = a[k];
    a[k] = a[k / 2];
    a[k / 2] = temp;
    k = k / 2;
  }
}



int main(void) { return 0; }