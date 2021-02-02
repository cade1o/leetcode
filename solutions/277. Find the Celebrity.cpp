/* The knows API is defined for you.
      bool knows(int a, int b); */
​
//time O(n) space O(n)
class Solution {
public:
    int findCelebrity(int n) {
        vector<int> check(n, 0);
        
        for( int i = 0 ; i < check.size() ; ++i ) check[i] = i;
        
        if( n <= 1 ) return -1;
        
        //O(2n) : n+ 1/2 n + 1/4 n + 1/8 n + ... = 2n
        while( check.size() > 1 ){
            for( int i = 0 ; i < check.size()-1 ; i++){    
                if( knows(check[i], check[i+1]) == 1 ) {
                    check.erase(check.begin()+i);
                }else check.erase(check.begin()+i+1);
            }
        }
        
        if( check.empty() ) return -1;
    
        //O(n)
        for( int i = 0 ; i < n ; i++) {
             if( check[0] != i && knows(check[0], i) == 1 ) return -1;
             if( check[0] != i && knows(i, check[0]) == 0 ) return -1;
        }
        return check[0];
    }
};
