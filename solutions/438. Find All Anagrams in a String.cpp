class Solution { // uofaxfcade
public:
    
    vector<int> findAnagrams(string s, string p) {
        
        string temp = "" ;
        vector<int> out ;
        int psize = p.length() ;
        int a[26] ,b[26] ,check;
        
        
        if ( psize > s.length() ) return out ;
        
        for ( int i = 0 ; i < 26 ; i ++ )
        {
            a[i] = 0 ;
            b[i] = 0 ;
        }
        
        for ( int i = 0 ; i < p.length() ; i ++ )
        {
            b[int(p[i])-97]++ ;
        }
            
        
            for ( int i = 0 ; i < s.length()-psize+1 ; i ++  )
            {          
                   check = 0 ;
                   temp = s.substr(i,psize) ;
        
                   for ( int j = 0 ; j < temp.length() ; j ++ )
                   {
                       a[int(temp[j])-97]++ ;
                   }
                   
                   for ( int j = 0 ; j < 26 ; j++ )
                   if ( a[j] != b[j] ) check = 1 ;
                   
                   if ( check == 0 ) out.push_back(i) ;
                
                   for ( int j = 0 ; j < 26 ; j ++ )
                   {
                       a[j] = 0 ;
                   }
            }
        
        return out ;
    }
};
