//O(n!)
class Solution {
public:
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        
        vector<vector<int>> grid (n, vector<int>(n, 0));
        
        dfs(grid, ans, 0, n);
        for( int i = 0 ; i < ans.size(); ++i ){
            int del = 0;
            for( auto &b: ans[i]){
                int count = 0;
                for( char c: b){
                    if ( c == '.' ) count++;
                }
                if( count == n ) { 
                    del = 1;
                }
            }
            if( del == 1) ans.erase(ans.begin()+i);
        }
        return ans;
        
    }
    
    // backtracking all possibilities
    void dfs( vector<vector<int>>& grid, vector<vector<string>>& ans, int row, int n){
        
        if( row == n ) {
            vector<string> res;
            for( int i = 0; i < n ; ++i){
                string temp = "";
                int count = 0;
                for( int j = 0 ; j < n ; ++j){
                    if( grid[i][j] == 0 ) {
                        temp+= ".";
                        count++;
                    }
                    if( grid[i][j] == 1 ) temp+= "Q";
                }
                if ( count == n ) return;
