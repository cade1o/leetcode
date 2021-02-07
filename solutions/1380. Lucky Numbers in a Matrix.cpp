class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_set<int> minimum;
        
        vector<int> out;
        //find mins
        for( int i = 0 ; i < matrix.size() ; ++i){
            int m = INT_MAX;
            for( int j = 0 ; j < matrix[0].size() ; ++j){
                 m = min(m, matrix[i][j]);
            }
            minimum.insert(m);
        }
        
        for( int i = 0 ; i < matrix[0].size() ; ++i){
            int m = INT_MIN;
            for( int j = 0 ; j < matrix.size() ; ++j){
                 m = max(m, matrix[j][i]);
            }
            if( minimum.count(m) != 0) out.push_back(m);
        }
        
        return out;
    }
};
