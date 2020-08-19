#include <iostream>
using namespace std;

// array-based symbol table (ordered)
template <typename Item, typename key> class ST {
private:
  Item null_item, *st;
  int size;

public:
  ST(int capacity) {
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
    for (int i = 0; i < N; i++) {
      if (!(st[i].Key() < v))
        break;
    }
    if (v == st[i].key())
      return st[i];
    return null_item;
  }

  Item select(int k) { return st[k]; }
  void show(ostream &os) {
    int i = 0;
    while (i < N) {
      st[i++].show(os);
    }
  }
};
int main(void) { return 0; }