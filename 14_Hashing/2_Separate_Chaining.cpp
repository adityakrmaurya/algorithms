/**
 * Separate Chaining:
 * Items that collide are chained together in separate linked lists
 *
 * Separate chaining reduces number of comparisons for sequential search by
 * factor of M (on the average), using extra space for M links
 *
 *
 **/
#include <iostream>
using namespace std;
/**
 * struct Item {
 *  int key;
 *  ...OTHER DATA...
 * }
 * int hash(key, capacity) {
 *   hash function scrambles key values sufficiently well that each of
 *   M lists is equally likely to be searched
 * }
 **/
template <typename Item, typename Key> class ST {
private:
  struct node {
    Key key;
    node *next;
    node(Key x, node n) {
      key = x;
      next = n;
    }
  };
  typedef struct node *link;
  link heads;
  int size, M;

public:
  ST(int capacity) {
    size = 0;
    M = capacity / 5;
    heads = new link[M];
    for (int i = 0; i < M; i++) {
      heads[i] = 0;
    }
  }
  Item search(Key v) { return searchR(heads[hash(v, M)], v); }
  void insert(Item item) {
    int i = hash(item.key(), M);
    heads[i] = new node(item, heads[i]);
    size++;
  }
};
int main(void) { return 0; }