class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
       unsigned int dp[target+1] ; 
        
        for ( int i = 0 ; i < target+1 ; i++ )
        {
            dp[i] = 0 ;
        }
        for ( int i = 0 ; i < nums.size() ; i ++ )
        {
            if ( nums[i] <= target )
            dp[nums[i]] = 1 ;
        }
        
          for (  int i = 1 ; i < target+1 ; i ++ )
          {
              
               for ( auto n: nums )
               {
                    if ( i - n >= 0 )   dp[i] += dp[i-n] ;    
               }
          } 
        
        return dp[target] ;
    }
};
