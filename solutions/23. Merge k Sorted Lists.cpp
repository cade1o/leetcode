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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int nums[20001] = {0};
        ListNode* empty = nullptr ;
        int emp = 0;
        if( lists.size() == 0 ) return empty;
    
        for( auto& a: lists){
            while( a != nullptr ){
                nums[a->val+10000]++;
                a = a->next;
                emp++;
            }
        }
    
        if( emp == 0 ) return empty;
        
        ListNode* res;
        ListNode* curr;
        int st = 0;
        for( int i = 0; i < 20001; ++i){
            while( nums[i] != 0){
                
                ListNode* node = new ListNode(i-10000);
                if( st == 0 ) {
                    
                    curr = new ListNode(node->val);
                    res = curr;
                    st++;
                    nums[i]--;
                    continue;
                }
                
                curr->next = node;
                curr = curr->next;
                st++;
                nums[i]--;
            }
        }
​
        return res;
    }
};
