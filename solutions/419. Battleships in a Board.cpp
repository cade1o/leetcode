class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        
        int num = 0 ;
        
        for ( int i = 0 ; i < board.size() ; i ++ )
        {
             for ( int j = 0 ; j < board[i].size() ; j ++ )
             {
                 if( board[i][j] == 'X' )       
                 {
                     if( i == 0 && j != 0 ) 
                     {
                         if( board[i][j-1] != 'X' ) num++ ;
                     }
                     
                     if( i != 0 && j == 0 )
                     {
                         if( board[i-1][j] != 'X' ) num++ ;
                     }
                     
                     if( i == 0 && j == 0 ) num++ ;
                         
                     if( i != 0 && j != 0 )
                     {
                         if( board[i][j-1] != 'X' && board[i-1][j] != 'X') num++ ;
                     }
                 }
             }
        }
        
        return num ;
    }
};
