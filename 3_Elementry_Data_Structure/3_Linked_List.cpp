/** Linked List = self referent = cyclic structure(node pointing to itself)
 * A basic data structure where each item contains the information that we need
 * to get to the next item.
 *
 * Capability to rearrange items efficiently at a cost of quick access i.e. to
 * access a element traverse whole of the linked list.
 **/
#include <iostream>

struct node {
  int value;
  node *next;
  node(int value, node *t) {
    this->value = value;
    next = t;
  }
};
typedef node *link;

link insert_front(int value, link head) {
  link temp = new node(value, head);
  return temp;
}

// It will not check if position is in range!
link insert_position(int value, link head, int position) {
  if (position == 0) {
    link temp = new node(value, head);
    return temp;
  }
  link start = head;
  while (--position) {
    head = head->next;
  }
  link temp = new node(value, head->next);
  head->next = temp;
  return start;
}
link insert_end(int value, link head) {
  link start = head;
  while (head->next != NULL) {
    head = head->next;
  }
  link temp = new node(value, NULL);
  head->next = temp;
  return start;
}
// Prints the list
void print(link start) {
  while (start != NULL) {
    std::cout << start->value << " ";
    start = start->next;
  }
}

// free all allocated memory
void free_mem(link start) {
  link temp = start;
  while (temp != NULL) {
    link t = temp;
    temp = temp->next;
    delete t;
  }
  delete temp;
}

int main(void) {
  link A = new node(1, NULL);
  link B = new node(2, NULL);
  link C = new node(3, NULL);
  A->next = B;
  B->next = C;
  print(A);
  std::cout << "\n-----------------------------\n";
  A = insert_front(5, A);
  print(A);
  std::cout << "\n-----------------------------\n";

  A = insert_position(0, A, 2);
  print(A);
  std::cout << "\n-----------------------------\n";

  A = insert_position(9999, A, 4);
  print(A);
  std::cout << "\n-----------------------------\n";
  A = insert_end(10000, A);
  print(A);
  free_mem(A);
  return 0;
}