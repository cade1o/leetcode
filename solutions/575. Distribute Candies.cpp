//Author: Cade
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int typesmax = candyType.size()/2 ;
        int count = 0 ;
        bitset<200001> all ;
        for ( int i: candyType ){
            if(!all.test(i+100000)){
                all.set(i+100000) ;
                count++ ;
                if( count == typesmax) break ;
            }
        }
        return count ;
    }
};
