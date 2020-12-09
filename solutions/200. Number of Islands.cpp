class Solution {
public:
    
  void dfs( vector<vector<char>>& z, int x, int y)
  {
      
      if( x > z.size()-1 || y > z[0].size()-1 || x < 0 || y < 0 || z[x][y] == '0' )
      return ;
      
      z[x][y] = '0' ;
      dfs( z, x+1, y ) ;
      dfs( z, x, y+1 ) ;
      dfs( z, x-1, y );
      dfs( z, x, y-1 );
      return ;
  }
    
  int numIslands(vector<vector<char>>& grid) {
    vector<vector<char>> v; //visited array
    v = grid ;
    int num = 0 ;
      
    for ( int i = 0 ; i < grid.size() ; i++ )
    {
        for ( int j = 0 ; j < grid[0].size() ; j++ )
        {
            
            if ( grid[i][j] == '1' ) 
            {
                dfs(grid,i,j ) ;
                num++ ;
            }
        }
    }
   
    return num;
  }
};
