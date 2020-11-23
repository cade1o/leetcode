class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> a ;
        
        for ( int i = 0 ; i < nums.size() ; i ++ )
        {
            if ( nums[i] == 0 ) a.push_back(nums[i]) ;
        }
        for ( int i = 0 ; i < nums.size() ; i ++ )
        {
            if ( nums[i] == 1 ) a.push_back(nums[i]) ;
        }
         for ( int i = 0 ; i < nums.size() ; i ++ )
        {
            if ( nums[i] == 2 ) a.push_back(nums[i]) ;
        }
        nums.clear() ;
        nums = a ;
    }
};
