//Author: Cade
class Solution {
public:
    int minAddToMakeValid(string S) {
​
         if ( S.size() == 0 ) return 0 ;
         int left = 0 , extraright = 0 ;
         for( char c: S){
         if( c == '(' ) left++;
                else{
                        if( left > 0 ) left--;
                  else extraright++ ;
               }
         }
         return left+extraright ;
    }
};
