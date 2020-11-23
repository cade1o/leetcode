class Solution {
public:
    bool isPalindrome(int x) {
        
        if ( x > 0 && x < 10 ) return true ;
        if ( x == 0 ) return true ;
        if ( x < 0 ) return false ;
        if ( x % 10  == 0 ) return false ;
        int f = 0 ;
        stringstream ss ;
        ss << x ;
        string str = ss.str();
        
   
            for( int i = 0 ; i < str.length()/2 ; i ++ )
            {
                if (str[i] != str[str.length()-1-i])
                f = 1 ;
            }
​
        if (f == 1 ) return false ; else return true ;
    }
};
