class Solution {
public:
    static bool com(pair<int,int>&a, pair<int,int>&b){
        return a.first > b.first || a.first == b.first && a.second < b.second;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> pq;
        
        int i = 0;
        
        int temp = 0;
        for( auto a: mat){
            for(int b: a){
                if( b == 0) temp++;
            }
            
            pq.push_back({temp, i});
            temp = 0;
            i++;
        }
        
        vector<int> out;
        sort(pq.begin(), pq.end(), com);
        for( int i = 0 ; i< k ;++i){
            out.push_back(pq[i].second);
        }
        return out;
    }
};
