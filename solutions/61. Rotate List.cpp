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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* circle = head;
        
        if ( head == nullptr ) return head;
        
        int length = 1;
        while(head->next != nullptr ){
            length++;
            head = head->next;
        } 
        
        int where = length - k%length;
        
        head->next = circle;
        for( int i = 0 ; i < where+1 ;++i){
            head = head->next ;
        }
        
        for( int i = 0 ; i < where-1 ;++i){
            circle = circle->next;
        }
        
        circle->next = nullptr;
        return head;
    }
};
