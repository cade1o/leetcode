class Solution {
public:
    int trap(vector<int>& height) {
        int length = height.size() ;
        
        // if (height.size() == 0 ) return 0 ;
        
        vector<int> l(length) ;
        vector<int> r(length) ;
        
        int rain = 0, start = 0, rmax = 0, lmax = 0 ;
        
        for ( int i = 0 ; i < height.size() ; i ++ )
        {
            l[i] = 0 ;
            r[i] = 0 ;
        }
        
        for ( int i = 0 ; i < height.size() ; i ++ )
        {
            if ( height[i] >= lmax )
            {
                lmax = height[i] ;
            }
            l[i] = lmax ;
        }
        
        for ( int i = height.size()-1 ; i >= 0 ; i -- )
        {
            if ( height[i] >= rmax )
            {
                rmax = height[i] ;
            }
            r[i] = rmax ;
        }
        
        for ( int i = 0 ; i < height.size() ; i ++ )
        {
            if ( height[i] == 0 && start == 0 ) continue; 
            
            start = 1 ;
            
            if ( l[i] > height[i] ) 
            { 
                
                if( l[i] > r[i] && height[i] <= r[i] ) rain += r[i] - height[i] ;
                if( r[i] > l[i] && height[i] <= l[i] ) rain += l[i] - height[i] ;
                if( r[i] == l[i] && height[i] <= l[i] ) rain += l[i] - height[i] ;
                
            }
