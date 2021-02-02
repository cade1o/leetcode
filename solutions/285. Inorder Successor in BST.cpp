/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//O(h)  h is bst height
class Solution {
public:
    
    TreeNode* inordersucc = nullptr;
    int m = INT_MAX;
    void find(TreeNode* a, int pval){
        if( !a ) return;
        
        if ( a->val <= pval ) find(a->right, pval);
        else{
            if( a->val < m ){
                inordersucc = a;
                m = a->val;
            }
            find(a->left, pval);
        }
        
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
         if( !p ) return p;
       
         find(root, p->val);
        
         return inordersucc;
    }
};
