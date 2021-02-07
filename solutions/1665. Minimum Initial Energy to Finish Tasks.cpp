//Cade
class Solution {
public:
    
​
    int minimumEffort(vector<vector<int>>& tasks) {
        
        int sum = 0;
​
        //learn from votrubac
        sort(begin(tasks), end(tasks), [](vector<int> &t1, vector<int> &t2) 
        { return t1[1] - t1[0] > t2[1] - t2[0]; });
        
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
