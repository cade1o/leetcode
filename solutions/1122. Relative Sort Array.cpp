class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int num[1001] = {0};
        for( auto &a: arr1) num[a]++;
        
        vector<int> out;
        
        for( auto &b: arr2){
            for( ; num[b] > 0 ; num[b]--){
                out.push_back(b);
            }
        }
        
        for( int i = 0 ; i < 1001 ; ++i){
            if( num[i] > 0 ){
                for( int j = 0; j < num[i]; j++) out.push_back(i);
            }
        }
        return out;
    }
};
