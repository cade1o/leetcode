// O(nlogn) Cade
class Solution {
public:
   
int lastStoneWeight(vector<int>& stones){
​
    priority_queue<int> p;
    
    //build max heap O(n*logn)
    for( int a: stones) p.push(a);
    
    // at most n-1 steps, so O(n*logn)
    while( p.size() > 1){
        
        int m1 = p.top(); // O(1)
        
        p.pop(); //O(logn+1)
        
        int m2 = p.top();
        
        p.pop();
        
        int diff = abs(m1 - m2);
​
        if( diff != 0 ) p.push(diff); //O(logn+1);
    }
    
    if( p.empty() ) return 0;
    
    return p.top();
}
​
};
