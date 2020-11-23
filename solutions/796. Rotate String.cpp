class Solution {
public:
    bool rotateString(string A, string B) {
        int size = A.length() ;
        string t ;
         if ( A == B) return 1 ;
         if ( A.length() != B.length() ) return 0 ;
       for ( int i = 0 ; i < size - 1 ; i ++ )
       {
            A = A + A[i] ;
       }
       
       for ( int i = 0 ; i < size ; i ++ )
       {
           t = A.substr(i,size) ;
           if ( t == B) return true ;
       }
      
       
        return 0 ;
    }
};
