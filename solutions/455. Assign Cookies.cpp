//O(n^2)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0;
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        for( int j = s.size()-1 ; j >= 0 ; --j ){
            for( int i = g.size()-1 ; i >= 0 ; --i ){
                if ( s[j] != -1 && g[i] != -1 && s[j] >= g[i] ){
                    res++;
                    s[j] = -1;
                    g[i] = -1;
                }
            }
        }
        
        return res;
    }
};
