class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> a;
        string check = "";
        int t = 0,p = 0 ;
        for( int i = 0 ; i < s.length() ; i ++ )
        {
            if ( s[i] == ' ' )
            {
                a.push_back( s.substr(t,i-t) ) ;
                t = i+1 ;
            }
        }
        
        for( int i = s.length() ; i > 0 ; i -- )
        {
            if ( s[i] == ' ') {
                a.push_back( s.substr(i+1,s.length()-i-1));
                break ;
            }
        }
        
        if ( pattern.length() == 1 ) return 1 ;
        if ( pattern.length() != a.size() ) return 0 ;
        
        for ( char x = 'a' ; x <= 'z' ; x ++)
        {
            check = "" ;
            for ( int i = 0 ; i < pattern.length() ; i ++ )
            {
                if ( pattern[i] == x && check == "") check = a[i] ;
                if ( pattern[i] == x && check != "" && check != a[i] ) p = 1 ;
            }
        }
        
            for ( int i = 0 ; i < pattern.length() ; i ++ )
            {
                for ( int j = i+1 ; j < pattern.length() ; j ++ )
                {
                    if ( pattern[i] != pattern[j] && a[i] == a[j] ) p = 1 ;
                }
            }
        
        
        if ( p == 1)
        return 0 ;
        else return 1 ;
    }
};
