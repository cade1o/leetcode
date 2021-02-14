class Solution {
public:
    bool check(string a){
        if( a.size() == 0 ) return 1;
        
        string b;
    
        if( a.size() % 2 == 0) {
            b = a.substr(0, a.size()/2);
            reverse(b.begin(), b.end());
            if( b == a.substr(a.size()/2, a.size()/2) ) return 1;
            else return 0;
        }
        
        if( a.size() % 2 == 1) {
            b = a.substr(0, a.size()/2);
            reverse(b.begin(), b.end());
            if( b == a.substr(a.size()/2 +1, a.size()/2) ) return 1;
        }
        return 0;
    }
    
    string shortestPalindrome(string s) {
        string res;
        unordered_map<char, int> dict;
        
        for(int i = 0 ; i < s.size() ; ++i){
            dict[s[i]]++;
        }
        int odd = 0;
        for(auto a: dict){
            
            if( a.second % 2 != 0) odd++;
        }
        
        if( check(s) == 1 ) return s;
        else {
            
            for ( int i = s.size()-1 ; i >= 0; i-- ){
                dict[s[i]]--;
                if( dict[s[i]] % 2 == 0) odd--;
                else odd++;
                
                if( odd > 1 ) continue;
                
                string left = s.substr(0, i);
                
                if( check(left) == 1)  
                {
                    string right = s.substr(i, s.size()-i);
​
                    reverse(right.begin(), right.end());
                    res = right+s;
                    return res;
                }
                
            }
        }
        
        return "";
    }
};
