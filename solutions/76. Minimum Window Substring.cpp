// O( s.size() ) : hashtable, 2 pointers, counter, head 
class Solution {
public:
​
    string minWindow(string s, string t) {
        vector<int> dict(128,0);
        
        if( s.size() < t.size() ) return "";
        
        string res = "";  
        for( char& a: t){
            dict[a]++;
        }
        string now;
        int st = 0, end = 0, count = t.size(), length = INT_MAX, head = 0;
        
        while( end < s.size() ) {
            
            if ( dict[s[end++]]-->0 ) count--;
            
            // valid
            while( count == 0 ){
                if( end-st < length) length = end-(head = st);
                if( dict[s[st++]]++== 0) count++; 
            }
        }
        
        return (length == INT_MAX)?"":s.substr(head,length) ;
    }
};
