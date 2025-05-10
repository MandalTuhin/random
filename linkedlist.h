#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
  int data;
  Node *next;
  Node(int value);
};

void printList(Node *head);
void insert_at_begin(Node *&head, int value);
void insert_at_end(Node *&head, int value);
void insert_after_kth(Node *&head, int value, int k);
void delete_first(Node *&head);
void delete_last(Node *&head);
void delete_at_kth_position(Node *&head, int k);

#endif
