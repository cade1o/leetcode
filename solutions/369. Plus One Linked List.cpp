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
    ListNode* plusOne(ListNode* head) {
        vector<int> digits(101, -1);
        int k = 1;
        
        ListNode* test = head;
        
        
        while( test != nullptr ){
            
            digits[k] = test->val;
            k++;
            test = test->next;
        }
        
        // support int
        int st = 0;
        
        for( int a = 100; a >= 0; --a){
            if( digits[a] != -1 ) {
                if( st == 0 )
                digits[a]++;
                
                st++; 
                if( digits[a] == 10 ) {
                    digits[a] = 0;
                    digits[a-1]++;
                }
            }
        }
        if( digits[0] == 0 ) digits[0]++;
        ListNode* empty = new ListNode(); 
        
        ListNode* res;
        ListNode* curr = new ListNode (0, empty);
        res = curr;
        
        int i = 0;
        if( digits[0] != 1 ) i = 1;
        
        // 
        
        while( digits[i] != -1 ){
            ListNode* empty = new ListNode(); 
            ListNode* temp = new ListNode (digits[i], empty);
            
            curr->next = temp;
           
            curr = curr->next;
            i++; 
            if( digits[i] == -1 ){
                curr->next = nullptr;
            }
            if( i > 100 ) break;
        }
        
        return res->next;
    }
};
