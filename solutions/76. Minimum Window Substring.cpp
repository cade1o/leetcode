class Solution {
public:
    bool check(string a, unordered_map<char,int> dict){
        unordered_map<char,int> word;
        for(char b: a){
            word[b]++;
        }
        
        for(auto b: dict){
            if( word[b.first] < dict[b.first] ) return 0;
        }
        return 1;
    }
    
    string minWindow(string s, string t) {
        unordered_map<char,int> dict;
        
        string res = "";  
        for( char& a: t){
            dict[a]++;
        }
   
        if( check(s, dict) == 0 ) return "";
        
        string now;
        int st = 0, end = 0;
        unordered_map<char,int> test = dict;
        
        while( dict.count(s[st]) == 0 && st < s.size() ) st++;
        if( end < st ) end = st;
        if( dict.count(s[st]) == 1 ) test[s[st]]--;
        
        while( end < s.size() ) {
            int c = 1;
​
            for( auto a:test ) {
                if( a.second > 0 ) c = 0;
            }
            if( c == 1 ){
                now = s.substr(st, end-st+1);
                ( res == "")? res = now:( res.size() > now.size() )?res = now:res = res;
                break;
            }
            
            end++;
            if( dict.count(s[end]) == 1 ) test[s[end]]--;
        }
        
        test[s[st]]++;
        st++;
        
        while( st < s.size() )
        {
            while( dict.count(s[st]) == 0 && st < s.size() ) st++;
            
