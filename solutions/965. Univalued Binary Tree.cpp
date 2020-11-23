/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
       
        
        return judge(root) ;
    }
    
    bool judge(TreeNode* a ){
        
        if ( a == 0 ) return true ;
        
        if ( a->left && a->left->val != a->val || a->right && a->right->val != a->val ) return false ;else return judge(a->left) && judge(a->right) ;
        
    }
};
