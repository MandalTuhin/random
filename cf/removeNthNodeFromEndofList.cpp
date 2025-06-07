#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *first = head;
    for (int i = 1; i < n; i++) {
      first = first->next;
    }
    ListNode *temp = first;
    ListNode *second = head;
    while (temp->next) {
      second = second->next;
      temp = temp->next;
    }

    while (first->next != second) {
      first = first->next;
    }

    first->next = second->next;
    second->next = nullptr;
    free(second);

    return head;
  }
};

int main() {
  ListNode *head = new ListNode(
      1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  ListNode *current = head;
  while (current) {
    cout << current->val << " ";
    current = current->next;
  }
  cout << "\n";

  Solution solution;

  head = solution.removeNthFromEnd(head, 2);
  current = head;

  while (current) {
    cout << current->val << " ";
    current = current->next;
  }
  cout << "\n";

  return 0;
}
