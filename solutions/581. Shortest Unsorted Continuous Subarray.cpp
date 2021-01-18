class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if( nums.size() == 1 ) return 0;
        int st = 0, end = 0 ,ma = nums[0], mi = nums[nums.size()-1];
​
        for( int i = 0; i < nums.size(); ++i){
            ma = max(ma,nums[i]);
            mi = min(mi,nums[nums.size()-1-i]);
            if( ma > nums[i] ) end = i;
            if( mi < nums[nums.size()-1-i] ) st = nums.size()-1-i;
        }
    
        if( end == st ) return 0;
    
        return end-st+1;
    }
};
