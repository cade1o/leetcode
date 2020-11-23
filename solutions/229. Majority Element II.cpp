class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        vector<int> ans;
        map<int,int> mp;
        for(int i=0;i<a.size();i++)
            mp[a[i]]++;
        for(auto it = mp.begin();it != mp.end();it++)
        {
            if(it->second > a.size()/3)
                ans.push_back(it->first);
        }
        return ans;
    }
};
