class Solution {
public:
    
    static bool sortbyfront2(const vector<int>& i,const vector<int>& j) 
    { 
         
        return i[0] < j[0] || ( i[0] == j[0] ) && i[1] < j[1];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> out ;
        int count[intervals.size()] ;
        
        if( intervals.size() <=1) return intervals; 
        
        sort(intervals.begin(),intervals.end(),sortbyfront2);
        
        for( int i = 0 ; i < intervals.size() ; i ++ )
        {  
            count[i] = 0;
        }
        
        for( int i = 0 ; i < intervals.size()-1 ; i ++ )
        {  
            if( intervals[i][1] >= intervals[i+1][0]  ) 
            {
               intervals[i+1][0] = intervals[i][0];
               intervals[i+1][1] = max(intervals[i][1],intervals[i+1][1]);
               count[i] = 1;
            }   
        }
        
        for( int i = 0 ; i < intervals.size() ; i ++ )
        {  
            if( count[i] == 0 ) 
            {
               out.push_back(intervals[i]);
            }   
        }
         
        return out;
    }
};
​
​
