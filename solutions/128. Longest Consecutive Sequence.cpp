class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        vector<int> dict;
        set<int> dup;
        if ( nums.size() == 0 ) return 0;
        if ( nums.size() == 1 ) return 1;
        
        for( auto &a: nums) {
            dict.push_back(a);
            dup.insert(a);
        }
        
       
        sort(dict.begin(), dict.end());
        
        int ans = 0, res = INT_MIN;
        
        for( int i = 1; i < dict.size(); ++i){
            if( dict[i] == dict[i-1] ) continue;
            if( dict[i]-dict[i-1] == 1 ){
                ans++;
                res = max(res, ans+1);
            }else {
                res = max(res, ans);
                ans = 0;
            }
        }
        
        return max(res, 1);
    }
};
