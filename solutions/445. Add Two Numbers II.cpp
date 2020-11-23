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
    ListNode* append(ListNode* l,int a ,int b)
    {
        
        ListNode* new_node = new ListNode() ;
            l->val = a ;
            if ( b != 1 )
            {
                l->next = new_node ;
                l = l->next ;
            }
        return l ;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a = 0 ,b = 0 , c = 0 ,d = 0 ,e = 0;
        string s1 = "" , s2 = "" , s3 ="" ;
          ListNode* l4 = new ListNode() ;
        ListNode* l3 = new ListNode() ;
    
          ListNode* l5 = new ListNode() ;
        ListNode* l6 = new ListNode() ;
    
        
        int a1 = 1 , a2 = 1 ;
        
        l5 = l1 ;
        l6 = l2 ;
        
        while ( l1  )
        {
            s1 += to_string(l1->val) ;
            l1 = l1->next ;
        }
        while ( l2  )
        {
            s2 += to_string(l2->val) ;
            l2 = l2->next ;
        }
        
