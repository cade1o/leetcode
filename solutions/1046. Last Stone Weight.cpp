class Solution {
public:
   int  findmax( vector<int>& s ){
    int ma = INT_MIN;
    for( int a: s){
        ma = max(ma,a);
    }
    for( int i = 0 ; i < s.size() ;i++){
        if( ma == s[i] ) {
            s.erase(s.begin()+i);
            break;
        }
    }
    
    return ma;
} 
​
int lastStoneWeight(vector<int>& stones){
​
        while( stones.size() > 1){
            for( int b: stones) cout<< b << " ";
            cout<< endl ;
            int a = abs(findmax(stones) - findmax(stones)) ;
            cout << a << endl ;
            if( a != 0 ) stones.push_back(a);
        }
    
        if( stones.size() == 0) return 0;
            return stones[0];
}
​
};
