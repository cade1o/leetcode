class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int b[301] = {0};
        
        for( auto a: nums){
            if( a <= 300 && a > 0) b[a] = 1;
        }
        
        for( int i = 1 ;  i <= 300 ; ++i){
            if( b[i] == 0 ) return i;
        }
        
        return 1;
    }
};
