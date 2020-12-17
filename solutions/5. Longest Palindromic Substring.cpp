            }
        }
        
        if( yes == 1 ) return 1 ;
        else return 0 ;
    }
    string longestPalindrome(string s) {
        int j = 1, k = 1 ;
        int temp = 0 , res = 0 ;
        if ( s.size() == 1 ) return s ;
        
        for( int i = 1 ; i < s.size() ; i ++ )
        {
            j = 1 ;
            k = 1 ;
            temp = 1 ;
            while ( i-j >= 0 && i+k <= s.size() - 1 )
            {
                if ( s[i - j] == s[i + k] ) temp+= 2 ;
                else break ;
                j++ ;
                k++ ;
            }
            if ( temp > res ) res = temp ;
        }
​
        for( int i = 1 ; i < s.size() ; i ++ )
        {
            temp = 0 ;
            j = 1 ;
            k = 0 ;
            while ( i-j >= 0 && i+k <= s.size() - 1 )
            {
                if ( s[i - j] == s[i + k] )  temp+= 2 ;
                else break ;
                j++ ;
                k++ ;
            }
            if ( temp > res ) res = temp ;
        }
        
        for ( int i = 0 ; i < s.size() ; i ++ )
        {
            if ( ispalin(s.substr(i,res)) == 1 ) return s.substr(i,res) ;
        }
        
        return s ;
    }
};
