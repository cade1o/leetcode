//Author: Cade
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int temp = 0 ;
        vector<int> time;
        int minx = INT_MAX ;
        int sub = 0 ;
        int edge = 0 ;
        for( string a: timePoints){
            temp = (a[0] - '0') * 600 + (a[1] - '0') * 60 + (a[3] - '0') * 10 + (a[4] - '0') * 1 ;
            time.push_back(temp) ;
        }
        sort(time.begin(),time.end()) ;
        
        for( int i = 0 ; i< time.size()-1 ; i++){
            sub = abs(time[i]-time[i+1]) ;
            if ( sub > 720) sub = 1440 - sub ;
            minx = min(sub, minx) ;
            if ( minx == 0 ) return 0 ;
        }
        edge = time[time.size()-1] - time[0] ;
        if ( edge > 720 ) edge = 1440 - edge ;
 
        return min(minx,edge) ;
    }
};
