//O(n) constant space
class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int inc = 0;
        unordered_map<int, char> dict;
        
        for( int i = 0 ; i < 26 ; ++i){
            dict[i] = 'a'+ i;
        }
        
        for( int i = shifts.size()-1 ; i >= 0 ; --i){
            inc += shifts[i];
            inc = inc%26;
            S[i] = dict[(S[i] - 'a' +inc) % 26];
        }
  
        return S;
    }
};
