//Cade 
class Solution {
public:
    string minInteger(string& num, int k) {
        char dig = '0';
        if( num[0] == '0' ) return num;
        
        int left = k, st = 0;
        while( left > 0 ){
            
            // if ( dig == '9' ) break;
            if( num[st] <= dig ) {
                st++; 
                if( st >= num.size()-1 ) break;
                dig = '0';
            }
            int find = 0;
            for( int i = st; i< num.size(); ++i){
                if( i - st > left ) break;
                if( num[i] == dig && i > st && dig < num[st] ){
                    if( i - st <= left ){
                        left -= i-st;
                        find = 1;   
                        for( int j = i; j >= st+1 ; j--){
                            num[j] = num[j-1];
                        }
                        num[st] = dig;
                        st++;
                        break;
                    }
                }
             
            }
            // cout<< num <<" "<< left << " "<< dig<< " " << st << endl;
            if( find == 0 && dig < '9' ) {
                dig++;
            }
        
        }
        
        return num;
    }
};
