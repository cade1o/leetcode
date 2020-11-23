class Solution {
public:
    int minStartValue(vector<int>& nums) {
        
        int min = 1 ;
        int sum = 0 ;
        
        for ( int i = 0 ; i < nums.size() ; i ++ )
        {
            sum+=nums[i] ;
            if ( sum < min ) min = sum ;
        }
        
        if ( min == 1 ) return 1;
        else 
        return -1*min+1 ;
    }
};
