class Solution {
public:
    int dp[101] ;
    int length ;
    
    
    int numDecodings(string s) {
        
        for ( int i = 0 ; i < s.size()-1 ; i ++ )
        {
            if ( s[i] == '0' && s[i+1] == '0' ) return 0 ;
        }
        
        if( s.size() == 1 && s == "0" ) return 0 ;
        
        length = s.size() ;
        
        for( int i = 0 ; i < 101 ; i ++ ) dp[i] = 0 ;
        
        if( length > 0 && s[0] != '0'  ) dp[1] = 1 ;
        
        if( length > 1 && s[1] != '0'  ) dp[2] = dp[1] ;
        if( length > 1 && s[0] != '0' && s.substr(0,2) < "27" ) dp[2] ++ ;
        
        
        if ( length > 2 )
        {
            for ( int i = 3 ; i < s.size() + 1 ; i ++ )
            {
                if( s[i-1] != '0' ) dp[i] += dp[i-1] ;
                if( s.substr(i-2,2) < "27" && s[i-2] != '0' ) dp[i] += dp[i-2] ;               
            }         
        }
        for ( int i = 1 ; i < 5 ; i++ ) cout<< dp[i] << endl ;
        return dp[length] ;
    }
};
