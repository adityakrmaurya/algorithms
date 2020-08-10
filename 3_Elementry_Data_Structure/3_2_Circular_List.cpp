// A representation of Josephus Problem using Circular List

#include <iostream>

struct node {
  int item;
  node *next;
  node(int x, node *t) {
    item = x;
    next = t;
  }
};
typedef struct node *link;

int main(int argc, char *argv[]) {
  // M = postion of person to remove
  // N = count of total person at start
  int N = atoi(argv[1]), M = atoi(argv[2]);
  link t = new node(1, NULL);
  t->next = t;
  link x = t;
  for (int i = 1; i < N; i++) {
    x = (x->next = new node(i, t));
  }
  while (x != x->next) {
    for (int i = 1; i < M; i++) {
      x = x->next;
    }
    x->next = x->next->next;
  }
  std::cout << x->item << std::endl;
}