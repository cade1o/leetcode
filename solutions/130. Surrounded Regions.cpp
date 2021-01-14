class Solution {
public:
    
    void solve(vector<vector<char>>& board) {
        int row = board.size() ;
        if ( row == 0 ) return ;
        
        int col = board[0].size() ;
        
        for( int i = 0 ; i < row ; i++ ){  
            for( int j = 0 ; j < col ; j++ ){
                if ( board[i][j] == 'O' && ( i == 0 || i == row-1 || j == 0 || j == col-1 ))                     dfs(board, i, j) ;
            }
        }
        
        for( int i = 0 ; i < row ; i++ ){  
            for( int j = 0 ; j < col ; j++ ){
                if ( board[i][j] == 'O' ) board[i][j] = 'X' ;
                if ( board[i][j] == 'K' ) board[i][j] = 'O' ;
            }
        }
        return ;
        
    }
    
    void dfs(vector<vector<char>>& board, int x , int y ){
        if ( x >= 0 && x < board.size() && y >= 0 && y < board[0].size() ) {
            if ( board[x][y] == 'O' ) {
                board[x][y] = 'K' ;
                dfs(board, x-1 , y) ;
                dfs(board, x+1 , y) ;
                dfs(board, x , y-1) ;
                dfs(board, x , y+1) ;
            }
        }
        return ;
    }
};
