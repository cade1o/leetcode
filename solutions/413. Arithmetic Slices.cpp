//time:O(n), space:O(1)
class Solution {
public:
    
    int numberOfArithmeticSlices(vector<int>& A) {
    
        int res = 0, st = 0, ed = 0, diff;      
        int newstart = 1, strange = 0;
        
        if( A.size() < 3) return 0;
        
        for( int i = 0 ; i< A.size() ;i++){
            if(newstart == 1) {
                st = i;
                diff = A[i+1] - A[i]; 
            }
            newstart = 0; 
            if( i == A.size()-1 || A[i] + diff != A[i+1]) {
                ed = i;
                if( i < A.size()-1 ){
                    if( A[i] + diff != A[i+1] ) strange = 1;
                }
                int a;
                if( (ed-st+1)>2 ) {
                    a = ed-st+1;
                    res += (1+(a-2))*(a-2)/2;
                }
                newstart = 1;
                if( i == A.size()-1 ) break;
                if(st != ed) i--;
            }
              
        }
        
        if(res == 0 && strange == 0) res = (1+(A.size()-2))*(A.size()-2)/2;
​
        return res;
    }
};
