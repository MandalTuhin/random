#include "linkedlist.h"
#include <iostream>
using namespace std;

int main() {
  Node *head = new Node(10);
  head->next = new Node(20);
  head->next->next = new Node(30);
  printList(head);
  insert_at_begin(head, 5);
  printList(head);
  insert_at_end(head, 35);
  printList(head);
  insert_after_kth(head, 0, 2);
  printList(head);
  delete_first(head);
  printList(head);
  delete_first(head);
  delete_first(head);
  delete_last(head);
  printList(head);
  return 0;
}
