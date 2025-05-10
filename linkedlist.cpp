#include "linkedlist.h"
#include <cstddef>
#include <iostream>

using namespace std;

Node::Node(int value) {
  data = value;
  next = nullptr;
}

void printList(Node *head) {
  Node *current = head;
  while (current != nullptr) {
    cout << current->data << " -> ";
    current = current->next;
  }
  cout << "NULL" << endl;
}

void insert_at_begin(Node *&head, int value) {
  Node *temp = new Node(value);
  temp->next = head;
  head = temp;
}

void insert_at_end(Node *&head, int value) {
  // insertion at end would require to traverse the entire ll, because I do not
  // have the pointer of the last element.
  Node *current = head;
  // I realized that I would have to stop one step earlier;
  while (current->next != nullptr) {
    current = current->next;
  }
  current->next = new Node(value);
}

// at a given position, well I would have to know/define what position means
// here, like do I start indexing from 0? or from 1?
// lets try 1, because linked lists are different from arrays. although the I
// may be able (it feels like that) to implement it using index 0;
// update: I think it will be clearer to use insert after kth element. that way
// 0 would mean insert at beginning, 1 would mean insert after one element and
// such.

void insert_after_kth(Node *&head, int value, int k) {
  if (k == 0) {
    insert_at_begin(head, value);

  } else if (k < 0) {
    cout << "cannot insert after " << k << " elements! \n";
  } else {
    int index = 1;
    Node *current = head;
    while (index < k && current != nullptr) {
      current = current->next;
      index++;
    }
    if (current != nullptr) {
      Node *temp = new Node(value);
      temp->next = current->next;
      current->next = temp;
    } else if (index != k - 1) {
      cout << " cannot insert after " << k
           << " elements, because the LL is not long enough! \n";
    } else {
      insert_at_end(head, value);
    }
  }
}

void delete_first(Node *&head) {
  if (head == nullptr) {
    cout << "no element in the linked list";
  } else {
    Node *temp = head;
    head = head->next;
    delete temp;
  }
}

void delete_last(Node *&head) {
  if (head == nullptr) {
    cout << "no element in the linked list";
  } else if (head->next == nullptr) {
    delete head;
    head = nullptr;
  } else {
    Node *current = head;
    while (current->next->next != nullptr) {
      current = current->next;
    }
    delete current->next;
    current->next = nullptr;
  }
}

void delete_at_kth_position(Node *&head, int k) {
  // I will be using 1 based indexing to keep things clear, so 1 means
  // delete the first element, 2 means delete the 2nd element. 3 means
  // delete the 3rd element and so on, I will have to check whether k is
  // less than the size of the linked list, and I can do this in the while
  // loop.
  if (k == 1) {
    delete_first(head);
  } else {
    int counter = 1;
    Node *current = head;
    while (counter < k && current->next->next != nullptr) {
      current = current->next;
      counter++;
    }
  }
};
