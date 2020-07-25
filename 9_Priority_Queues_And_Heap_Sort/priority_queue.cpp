#include <iostream>

template <class T> class PQ {
private:
  T *pq;
  int size;

public:
  PQ(int capacity) {
    pq = new T[capacity];
    size = 0;
  }
  bool empty() const { return size == 0; }
  void insert(T item) { pq[size++] = item; }
  T get_max() {
    int max_index = 0;
    for (int i = 0; i < size; i++) {
      if (pq[i] > pq[max_index])
        max_index = i;
    }
    T temp = pq[max_index];
    pq[max_index] = pq[size - 1];
    pq[size - 1] = temp;
    return pq[--size];
  }
};

int main() {}