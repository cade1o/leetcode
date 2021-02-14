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
    bool isCompleteTree(TreeNode* root) {
         if( !root ) return 0;
         queue<TreeNode*> bfs;
        bfs.push(root);
        
        vector<int> check;
        
        while( !bfs.empty() ){
            if(bfs.front() == nullptr ) {
                check.push_back(0);
               
            }else {
                check.push_back(bfs.front()->val);
                bfs.push(bfs.front()->left);
                bfs.push(bfs.front()->right);
            }
            bfs.pop();
            
        }
        
        for( int i = check.size()-1 ; i >=0 ; --i){
            if( check[i] != 0 ) break;
            if( check[i] == 0 ) check.erase(check.begin()+i);
        }
        for( auto a : check) if( a == 0) return 0;
        return 1;
        
        
    }
};
