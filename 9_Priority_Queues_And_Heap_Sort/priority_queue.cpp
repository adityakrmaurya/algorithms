/* 
 * Unordered Array Representation
 * Time Complexity:
 * insert: O(1)
 * remove maximum: O(N) 
 * remove: O(1)
 * find maximum: O(N) 
 * change priority: 1
 * join: O(N)
 *
 */
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

int main() {
  PQ<char> pq(20);
  pq.insert('B');
  pq.insert('E');
  std::cout << pq.get_max();
  pq.insert('S');
  pq.insert('T');
  pq.insert('I');
  std::cout << pq.get_max();
  pq.insert('N');
  std::cout << pq.get_max();
  pq.insert('F');
  pq.insert('I');
  pq.insert('R');
  std::cout << pq.get_max();
  pq.insert('S');
  pq.insert('T');
  std::cout << pq.get_max();
  std::cout << pq.get_max();
  pq.insert('O');
  pq.insert('U');
  std::cout << pq.get_max();
  pq.insert('T');
  std::cout << pq.get_max();
  std::cout << pq.get_max();
  std::cout << pq.get_max();
  std::cout << pq.get_max();
  std::cout << pq.get_max();
  std::cout << pq.get_max();
  std::cout << pq.get_max();
  // ETSRTSUTONIIFB
}