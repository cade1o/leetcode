//Cade
class Solution {
public:
    
    static bool com(vector<int>& a, vector<int>&b){
        return a[1]-a[0] > b[1]-b[0];
    }
    
    int minimumEffort(vector<vector<int>>& tasks) {
        
        int sum = 0;
​
        int size = tasks.size();
        sort(tasks.begin(), tasks.end(), com);
        
        for( auto &a: tasks){
            sum += a[0];
        }
        
        int res = sum;
        for( auto &a: tasks){
            if( sum >= a[1]) sum-= a[0];
            else {
                res += a[1] - sum;
                sum = a[1] - a[0];
            }
        }
        
        return res;
    }
};
