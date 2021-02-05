//m = firstList.size(), n = secondList.size()
//time: less or equal to O(m+n) 
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> out;
       
        int st, end, i , j;
        for( i = 0, j = 0 ; i < firstList.size() || j < secondList.size() ; ){
            if( i == firstList.size() || j == secondList.size() ) break; 
            if ( firstList[i][0] <= secondList[j][0] ){
                
                if( firstList[i][1] < secondList[j][0] ){
                    i++;
                    continue;
                }
                st = secondList[j][0];
                if( firstList[i][1] <= secondList[j][1] ) {
                    end = firstList[i][1];
                    i++;
                }else{
                    end = secondList[j][1];
                    j++;
                }
                out.push_back({st, end});
            }else{
                if( firstList[i][0] > secondList[j][1] ){
                    j++;
                    continue;
                }
                st = firstList[i][0];
                if( secondList[j][1] <= firstList[i][1] ){
                    end = secondList[j][1];
                    j++;
                }else{
                    end = firstList[i][1];
                    i++;
                }
                out.push_back({st, end});
            }
        }
​
        return out;
    }
};
