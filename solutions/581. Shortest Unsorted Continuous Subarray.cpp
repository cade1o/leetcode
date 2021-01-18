class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if( nums.size() == 1 ) return 0;
        int mina = INT_MAX, end = INT_MIN;
        stack<int> abc;
​
        for( int i = 0; i < nums.size(); ++i){
            while( !abc.empty() && nums[i] < nums[abc.top()] ){
                mina = min(mina,abc.top());
                abc.pop();
                end = i;
            }
            abc.push(i);
        }
        while(!abc.empty()) abc.pop();
        
        for( int i = nums.size()-1; i > -1; --i){
            while( !abc.empty() && nums[i] > nums[abc.top()] ){
                end = max(end,abc.top());
                abc.pop();
            }
            abc.push(i);
        }
        if( mina == INT_MAX ) return 0;
    
        return end-mina+1;
    }
};
