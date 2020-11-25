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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int t ;
        vector<int> a,b ;
        
        while( l1 != nullptr )
        {
            a.push_back(l1->val) ;
            l1 = l1->next ;
        }
        
        while( l2 != nullptr )
        {
            b.push_back(l2->val) ;
            l2 = l2->next ;
        }
        
        if( a.size() > b.size() ) 
        {
            t = a.size() - b.size() ;
            for ( int i = 0 ; i < t ; i ++ )
            {
                b.push_back(0);
            }
        }
        else 
        {
            t = b.size() - a.size() ;
            for ( int i = 0 ; i < t ; i ++ )
            {
                a.push_back(0);
            }
        }
        
        a.push_back(0);
        b.push_back(0);
        
        for ( int i = 0 ; i < a.size() ; i ++ )
        {
            a[i] = a[i] + b[i] ;
            if ( a[i] > 9 ) 
            { 
                a[i] = a[i] - 10 ;
                a[i+1] ++;
            }
        }
               
