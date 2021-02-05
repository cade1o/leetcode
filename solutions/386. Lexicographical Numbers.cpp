class Solution {
public:
    
    static bool com2(string &a, string& b){
    
        int sizem = min(a.size(), b.size());
        for( int i = 0 ; i < sizem ; ++i){
            if( a[i] < b[i] ) return 1; 
            if( a[i] > b[i] ) return 0;
        }
​
        return a.size() < b.size();
    }
    
    vector<int> lexicalOrder(int n) {
        vector<string> temp;
        vector<int> out;
        if( n <= 0 ) return out;
        
        for( int i = 1 ; i <= n ; ++i){
            temp.push_back(to_string(i));
        }
     
        sort(temp.begin(), temp.end(), com2);
​
        for( auto a: temp){
            out.push_back(stoi(a));
        }
        
        return out;
    }
};
