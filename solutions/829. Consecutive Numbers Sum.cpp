class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int ways = 0 ;
        double K = N ;
        
        if ( N == 1 ) return 1 ;    
       
        if ( fmod(K,2.0) != 0.0 )
        {      
                for ( double i = 1 ; i < sqrt(K) + 1 ; i += 2 )
                {
                    if ( fmod(K,i) == 0.0  ) 
                    {
                        ways ++ ;
                        if ( fmod(K/i,2.0) != 0.0 & i != 1 && K/i != i) ways ++ ;
                    }
                }
                ways ++ ;
        }
        else
        {
            while( fmod(K,2.0) == 0.0 ) K = K / 2 ;
           
                if( K > 1 )
                {
                    for ( double i = 1 ; i < sqrt(K) + 1 ; i += 2 )
                    {
                        if ( fmod(K,i) == 0.0  ) 
                        {
                            ways ++ ;
                            if ( fmod(K/i,2.0) != 0.0 && i != 1 && K/i != i) ways ++ ;        
                        }
                    }  
                }
                ways ++ ;
        }
        return ways ;
    }
};
​
​
