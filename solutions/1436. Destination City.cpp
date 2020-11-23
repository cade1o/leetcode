class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
       unordered_set<string> a ;
        
        for ( int i = 0 ; i < paths.size() ; i ++ )
        {
            a.insert(paths[i][0]) ;
        }
     
        for ( int i = 0 ; i < paths.size() ; i ++)
        {
            if ( a.find(paths[i][1]) == a.end() ) return paths[i][1] ;
        }
        
        return "" ;
    }
};
