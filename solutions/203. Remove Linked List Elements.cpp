/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* sentinel = new ListNode(0);
    sentinel->next = head;
  
​
    ListNode *prev = sentinel, *curr = head, *temp = nullptr;
    while (curr != nullptr) {
      if (curr->val == val) {
        prev->next = curr->next;
        temp = curr->next;
        delete curr;
      } else {
          prev = curr;
          temp = curr->next;
      }
     
      curr = temp;
    }
​
    ListNode *ret = sentinel->next;
    delete sentinel;
    return ret;
  }
};
