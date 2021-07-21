class Solution {
public:
    //O(logn) binary search
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0, end = n-1, mid = -1;
        
        while( st <= end ){
            mid = (st+end)/2;
            if( nums[mid] == target ) return mid;
            if( nums[end] == target ) return end;
            if( nums[st] == target ) return st;
            
            if( nums[mid] < nums[st] ){
                if( target > nums[mid] && target > nums[st] ) { end = mid-1; continue;}
                if( target > nums[mid] && target < nums[end] ) { st = mid+1; continue;}
                if( target < nums[mid] ) { end = mid-1; continue;}
                if( target > nums[end] && target < nums[st] ) return -1;
            }
            if( nums[mid] > nums[st] ){
                if( target < nums[mid] && target > nums[st] ) { end = mid-1; continue;}
                if( target < nums[mid] && target < nums[end] ) { st = mid+1; continue;}
                if( target > nums[mid] ) { st = mid+1; continue;}
                if( target > nums[end] && target < nums[st] ) return -1;
            }
            
            break;
        }
        
        return -1;
    }
};
