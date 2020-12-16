class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> b,l ;
        b = nums ;
        l = nums ;
        if ( nums.size() == 1 ) return nums[0] ;
        int sum = 0, max = -100000 , m = nums[0] , bmax = 0 , flip = 0;
        for ( int i = 0 ; i < nums.size() ; i ++ )
        {
            if(nums[i] > 0) flip = 1 ;
            sum+= nums[i] ;
            b[i] = sum ;
            if ( b[i] > bmax) bmax = b[i] ;
            if ( nums[i] > m) m = nums[i] ;
        }
        
        l[b.size()-1] = b[b.size()-1] ;
        max = l[b.size()-1] ;
        
        for ( int i = b.size()-1 ; i > 0 ; i -- )
        {
            if ( l[i] < b[i] )
            l[i-1] = b[i] ;
            else l[i-1] = l[i] ;
            
            if ( l[i] - b[i] > max ) max = l[i] - b[i] ;
        }
        if ( l[0]- b[0] > max ) max = l[0] - b[0] ;
        
        if ( bmax > max ) max = bmax ;
        
        if(flip == 1)
        return max ;
        else return m ;
    }
};
