class Solution {
private:
    
   int p (int a ,int b){
        int res = 1;
        
        if ( a < b ) return 0 ;
        if ( b < 0 ) return 0 ;
        
        if ( b == 0 ) return 1 ;
        
        for ( int i = 0 ; i < b ; i ++ )
        {
            res *= a ;
            a-- ;
        }
        
        return res ;
        
    }
    
    
public:
    int numDupDigitsAtMostN(int N) {
        vector<int> number ;
        
      
        
         N++ ;
        string num ;
        int n , invalid = 0;
        int digit = 0 ;
        
        num = to_string(N) ;
        for ( int i = 0 ; i < num.size() ; i++ )
        {
            digit = num[i]-'0';
            number.push_back(digit) ;
        }
        
    
        n = number.size() ;
        
        unordered_set<int> seen ;
        
        for ( int i = 1 ; i < n ; i ++ )
        {
            invalid += 9*p(9,i-1) ;
        }
        
      
    
        for (int i = 0; i < n; i++) {
            for (int j = i > 0 ? 0 : 1; j < number[i]; j++) {
                if (seen.find(j) == seen.end()) {
                    invalid += p(9 - i, n - i - 1);
                }
            }
            if (seen.find(number[i]) != seen.end()) {
                break;
            }
            seen.insert(number[i]);
        }
        
        
        return N-invalid;
    }
};
