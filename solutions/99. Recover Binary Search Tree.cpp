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
    void helper(TreeNode* root) {
    
        while( check(root, root, root->left, -1) == 0 || check(root, root, root->right, 1) == 0 ){
            repair(root, root, root->left, -1);
            repair(root, root, root->right, 1);
        }
        return;
    }
    
    void recoverTree(TreeNode* root) {
    
        travel(root);
        
        return;
    }
    
    void travel(TreeNode* root){
        if( !root ) return;
        helper(root);
        recoverTree(root->left);
        recoverTree(root->right);
        return;
    }
    bool check( TreeNode* root, TreeNode*& p, TreeNode*& node, int di){
        if( !node ) return 1;
​
        if( di == -1 && node->val >= root->val ) return 0;
        if( di == 1 && node->val <= root->val ) return 0;
