class Solution {
public:
    int fixedPoint(vector<int>& A) {
       int s = 0 , e = A.size()-1 , m , out = 100000;
       
       while ( s != e )
       {
           m = (s+e)/2 ;
           
           if ( A[m] < m )
           s = m+1 ;
           else e = m ;
           
           if ( A[m] == m && m < out ) out = m ;
       }
       if ( out < A.size() ) return out ;
       else return -1 ;
    }
};
