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
    
    static bool com(pair<int,int>&a, pair<int,int>&b){
        return a.second < b.second;
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<pair<int,int>>> output(100, vector<pair<int,int>>(1,{0,0}));
        vector<vector<int>> res;
        vector<int> temp;
      
        //O(n) n is number of nodes
        tra(root, 50, 0, output);
        
        //?
        for( int i = 0 ; i < output.size() ; ++i){
            if( output[i].size() > 1 ) {
                output[i].erase(output[i].begin());
                sort(output[i].begin(), output[i].end(), com);
                for( auto a: output[i]){
                    temp.push_back(a.first);
                }
                res.push_back(temp);
                temp.clear();
            }
        }
        
        return res;
    }
    
    void tra(TreeNode* root, int a, int b, vector<vector<pair<int,int>>>& out){
        if(!root) return;
​
        out[a].push_back({root->val,b});
  
        tra(root->left, a-1, b+1, out);
        tra(root->right, a+1, b+1, out);
    }
};
