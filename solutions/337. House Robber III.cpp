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
 *
 **/
class Solution {
public:
    int rob(TreeNode* root) {
        
        return maximum(root,1);
    }
    
    int maximum(TreeNode* root, int canrobornot){
        int sum1, sum2;
        
        // if the input node is empty, return 0
        if( !root) return 0;
        
        if( canrobornot == 1 ){
            
            // the node itself plus 2 subtrees' esults
            sum1 = maximum(root->left, 0) + maximum(root->right, 0) + root->val;
            
            // do not rob this node, but rob all two susbtrees
            sum2 = maximum(root->left, 1) + maximum(root->right, 1);
            
            // return the bigger sum
            return max(sum1, sum2);
        }
        
        //else if canrobornot = 0
        sum2 = maximum(root->left, 1) + maximum(root->right, 1);
        return sum2;
    }
};
