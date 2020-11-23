class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int l = cost.size() ;
        int dp[1001] ;
        dp[1] = cost[0] ;
        dp[2] = cost[1] ;
        
        if ( cost.size() > 2 )
        {
            for ( int i = 3 ; i < cost.size()+1 ; i ++ )
            {
                dp[i] = min(dp[i-1],dp[i-2]) + cost[i-1] ;
            }
            return min(dp[cost.size()],dp[cost.size()-1]) ;
        }
        
​
        else return min(dp[1],dp[2]) ;
    }
};
