#include <iostream>
using namespace std;

// for Item Class see 1_Symbol-Table
// array-based symbol table (ordered)
template <typename Item, typename Key> class STA {
private:
  Item null_item, *st;
  int size;

public:
  STA(int capacity) {
    st = new Item[capacity + 1];
    size = 0;
  }
  int count() { return size; }
  void insert(Item x) {
    int i = size++;
    Key v = x.key();
    while (i > 0 && v < st[i - 1].key()) {
      st[i] = st[i - 1];
      i--;
      st[i] = x;
    }
  }
  Item search(Key v) {
    for (int i = 0; i < size; i++) {
      if (!(st[i].Key() < v))
        break;
      if (v == st[i].key())
        return st[i];
    }
    return null_item;
  }
  Item select(int k) { return st[k]; }
  void show(ostream &os) {
    int i = 0;
    while (i < size) {
      st[i++].show(os);
    }
  }
};

// Linked List Based Symbol Tables
template <typename Item, typename Key> class STLL {
private:
  Item null_item;
  struct node {
    Item item;
    node *next;
    node(Item x, node *t) {
      item = x;
      next = t;
    }
  };
  typedef node *link;
  int N;
  link head;
  Item searchR(link t, Key v) {
    if (t == 0)
      return null_item;
    if (t->item.key() == v)
      return t->item;
    return searchR(t->next, v);
  }

public:
  STLL(int maxN) {
    head = 0;
    N = 0;
  }
  int count() { return N; }
  Item search(Key v) { return searchR(head, v); }
  void insert(Item x) {
    head = new node(x, head);
    N++;
  }
};
int main(void) { return 0; }