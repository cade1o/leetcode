class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> sum;
        sum[0] = 1;
        int tempsum = 0;
        for( auto& a: nums){
            tempsum += a;
            sum[tempsum]++;
            if( sum.count(tempsum-k) != 0) ans+= sum[tempsum-k];
            if( k == 0 ) ans--;
        }
        
        return ans;
    }
};
