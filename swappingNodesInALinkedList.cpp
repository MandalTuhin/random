#include <iostream>
#include <vector>
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
  ListNode *swapNodes(ListNode *head, int k) {
    vector<int> linkedArray;
    ListNode *current = head;
    while (current != nullptr) {
      linkedArray.push_back(current->val);
      current = current->next;
    }
    cout << "for Vector: ";
    for (int elem : linkedArray) {
      cout << elem << " ";
    }
    cout << "\n";
    swap(linkedArray[k - 1], linkedArray[linkedArray.size() - k]);

    cout << "Vector after swapping: ";
    for (int elem : linkedArray) {
      cout << elem << " ";
    }
    cout << "\n";

    int i = 0;
    current = head;
    while (current != nullptr) {
      current->val = linkedArray[i++];
      current = current->next;
    }

    return head;
  }
};

int main() {
  ListNode *head = new ListNode(
      1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  Solution solution;
  ListNode *current = head;
  while (current != nullptr) {
    cout << current->val << " ";
    current = current->next;
  }
  cout << "\n";
  head = solution.swapNodes(head, 2);
  current = head;
  while (current != nullptr) {
    cout << current->val << " ";
    current = current->next;
  }
}
