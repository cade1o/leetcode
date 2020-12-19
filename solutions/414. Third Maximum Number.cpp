class Solution {
public:
    int thirdMax(vector<int>& nums) {
    long long max1, max2, max3;
    max1 = max2 = max3 = LLONG_MIN;
    for (auto num : nums) {
        if (num <= max3 || num == max2 || num == max1) continue;
        max3 = num;
        if (max3 > max2) swap(max2, max3);
        if (max2 > max1) swap(max1, max2);
    }
    return max3 == LLONG_MIN ? max1 : max3 ;
    }
};
