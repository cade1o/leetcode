class Solution {
public:
    string removeOuterParentheses(string S) {
        int start = 0;
        string temp ;
        vector<string> out;
        if( S == "" ) return "" ;
        int a = 0 ;
        
        for ( int i = 0 ; i < S.length() ; i ++ )
        {
            if ( S[i] == '(' )  a++ ; 
            else a-- ;
            
            cout << a << endl ;
            if ( a == 0 ) 
            {
​
                temp = S.substr(start,i+1-start) ;
 
                out.push_back(temp) ;
                start = i+1 ;
                temp = "" ;
            }
        }
        
        for ( int i = 0 ; i < out.size() ; i ++ )
        {
            
            out[i] = out[i].substr(1,out[i].length()-2) ;
        }
        
        temp = "" ;
        
        for ( int i = 0 ; i < out.size() ; i ++ )
        {
            temp += out[i] ;
        }
        return temp ;
    }
};
