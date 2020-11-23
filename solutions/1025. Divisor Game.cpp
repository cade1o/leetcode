class Solution {
public:
    bool divisorGame(int N) {
        int dp[1001] ;
        vector<int> t;
        dp[1] = 0 ;
        dp[2] = 1 ;
        dp[3] = 0 ;
        
        dp[4] = 1 ;
        dp[5] = 0 ;
            
        for ( int i = 6 ; i < 1001 ; i ++ )
        dp[i] = 0 ;
        
        if ( N > 5 )
        {
            for ( int i = 6 ; i < N+1 ; i ++ )
            {
                for ( int j = 1 ; j < i ; j ++ )
                {
                    if ( i % j == 0 ) t.push_back(j);
                }
​
                for ( int j = 0 ; j < t.size() ; j ++ )
                {
                    if ( dp[i-t[j]] == 0 ) dp[i] = 1 ;
                    break ;
                }
                t.clear() ;
            }
        }
        return dp[N] ;
    }
};
