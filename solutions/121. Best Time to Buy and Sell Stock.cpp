class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> max ;
        max = prices ;
        int tempmax = 0 , minus = 0, temp = 0;
        
        if ( prices.size() <= 1 ) return 0 ;
        if ( prices.size() == 2 ) 
        {
            if ( ( prices[1] - prices[0]) > 0 ) return prices[1] - prices[0] ; 
            else return 0 ;
        }
         max[prices.size() - 2] = max[prices.size() - 1] ;
        
        tempmax = prices[prices.size()-1] ;
        for ( int i = prices.size() - 2 ; i >= 0 ; i -- )
        {
            if ( ( prices[i+1] ) > tempmax )
            {
                max[i] = prices[i+1] ;
                tempmax = prices[i+1] ;
            }
            else max[i] = tempmax ;
        }
        minus = max[0] - prices[0] ;
        
        for ( int i = 0; i <= prices.size() - 2 ; i ++ )
        {
            temp = max[i] - prices[i] ;
            if ( temp > minus ) minus = temp ;
        }
    
        if ( minus > 0 ) return minus;
        else return 0 ;
    }
};
