//Union-find solution from fancy1984
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> p(1010, 0);
        for(int i = 0; i < p.size(); i++ )
            p[i] = i;
​
        for(auto &v : edges ){
            int n1 = v[0], n2 = v[1];
            while(n1 != p[n1]) n1 = p[n1]; // find n1's root
            while(n2 != p[n2]) n2 = p[n2]; // find n2's root
            if( n1 == n2 )
                return v;
            else
                p[n2] = n1;
        }
        return {};
    }
};
