class Solution {
public:
    int findNthDigit(int n) {
        int sum[11] ={0};
        sum[9] = INT_MAX;
        int tsum = 0;
        for( int i = 1; i <= 8 ; ++i){
             tsum += i*9*pow(10,i-1);
             sum[i] = tsum;
        }
        
        int index, m, base;
        for( int i = 0; i <= 8 ; ++i){
            if( n > sum[i] && n <= sum[i+1] ){
                index = (n - sum[i])/(i+1);
                m = (n-sum[i])%(i+1);
                base = i;
            }
        }
        int num;
        if(  m == 0 )
        num = pow(10, base) + index - 1;
        else num = pow(10, base) + index;
        
        string s = to_string(num);
        char temp;
        int res;
        
        if( m == 0 ) temp = s[s.size()-1];
        else temp = s[m-1];
        
        res = temp - '0';
        
        return res; 
    }
};
