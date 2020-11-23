class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> set;
        for(int i = 0; i < nums.size(); i++) {
            if (set.count(nums[i])>0) {
                set.erase(nums[i]);
            } else {
                set.insert(nums[i]);
            }
        }
        for(auto x : set) {
           return x;
        }
        return -1;
    }
};
