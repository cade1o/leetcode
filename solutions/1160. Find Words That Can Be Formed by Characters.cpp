class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> c;
        unordered_map<char,int> a;
        for ( char b = 'a' ; b<= 'z' ; b++ )
        {
            c[b] = 0 ;
        }
        
        int out = 0 ;
        
        for ( int i = 0 ; i < chars.length() ; i ++ )
        {
            c[chars[i]] ++  ;
        }
        
        for ( int i = 0 ; i < words.size() ; i ++ )
        {
            a = c ;
            for ( int j = 0 ; j < words[i].length() ; j ++ )
            {
                if ( a[words[i][j]] > 0 &&  j == words[i].length() - 1 ) {
                    out+=   words[i].length() ;
                    cout << words[i] ;
                }
                
                if ( a[words[i][j]]  > 0  ) {
                    a[words[i][j]] -- ;
                    continue;
                }   else break ;
            }
        }
        return out ;
    }
};
