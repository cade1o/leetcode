class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int size = nums1.size() + nums2.size();
        
        if( size == 0) return 0;
        
        if( size == 1 && nums1.size() == 0 ) return nums2[0];
        if( size == 1 && nums2.size() == 0 ) return nums1[0];
        
        int mid;
        
        double res = 0.0;
        if( size%2 == 1){
            mid = (size+1)/2;
            for( int i = 0, j = 0 ; i < nums1.size() || j < nums2.size() ; ){
                
                if( i < nums1.size() && j < nums2.size() ){
                    if( nums1[i] <= nums2[j]){
​
                        if( mid == 1) res = nums1[i];
                        i++;
                         mid--;
                        continue;
                    }else{
                        if( mid == 1) res = nums2[j];
                        j++;
                         mid--;
                        continue;
                    } 
                }
                
                if( i == nums1.size() && j< nums2.size()) {
                    if( mid == 1) res = nums2[j];
                    j++;
                     mid--;
                    continue;
                }
                 if( j == nums2.size()&& i< nums1.size()) {
                    if( mid == 1) res = nums1[i];
                    i++;
                      mid--;
                    continue;
                }
            }
        }else{
            
            mid = size/2;
            for( int i = 0, j = 0 ; i < nums1.size() || j < nums2.size() ; ){
                if( i < nums1.size() && j < nums2.size() ){
                    if( nums1[i] <= nums2[j]){
