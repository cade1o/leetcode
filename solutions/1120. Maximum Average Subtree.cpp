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
    double sum = 0, num = 0;
    double m = -1, temp;
    double maximumAverageSubtree(TreeNode* root) {
        
        count(root);
        return m;
    }
    
    void count( TreeNode* root){
        if( root == nullptr ) return;
        travel(root);
        temp = sum/num;
        m = max(m, temp);
        sum = 0;
        num = 0;
        count( root->left);
        count(root->right);
    }
    void travel(TreeNode* root ){
        if(root == nullptr ) return;
        
        sum+= root->val;
        num++;
        travel( root->left);
        travel(root->right);
    }
};
