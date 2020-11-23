//cadexfuofa
class Solution {
public:
    int reverse(int x) {
        
        int neg;
        stringstream ss , gg ,kk;
        ss << x;
        string str = ss.str();
        string str2 ;
        int out ;
        
        
        if ( x < 0 ) neg = 1 ; else neg = 0 ;
        
        for ( int i = 0 ; i < str.length() ; i ++ )
        {
            str2 += str[str.length()-i-1] ;
        }
        
       
​
  gg << str2;  
  gg >> out;  
       
         cout<< str2 << endl ;
            
        kk << out ;
        string str3 = kk.str() ;
         
        cout<< str3 ; 
        
        if ( x == -2147483648 ) return 0 ;
        
        if ( ( str3 !=str2 ) && ( neg !=1 ) && ( str2[0] != '0' ) ) return 0 ;
        if ( neg == 1 ) {
            
            out = out*(-1) ;
          
        }
        
        if ( out == -2147483647 ) return 0 ;
        return out ;
    }
};
