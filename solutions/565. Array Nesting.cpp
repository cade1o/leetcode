class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        
      int a[nums.size()] ,key ,temp , length = 0 , max = 0 ;
      
      // initialise
      for ( int i = 0 ; i < nums.size() ; i ++ )
      {
          a[i] = 0 ; 
      }  
        
      for ( int i = 0 ; i < nums.size() ; i ++ )
      {
         key = nums[i] ;
         length ++ ;
         a[i] = 1 ;
         if ( length > max ) max = length ;
         while ( a[key] == 0 )
         {
             a[key] = 1 ; 
             key = nums[key] ; 
             length ++ ;
             if ( length > max ) max = length ;
         }
         if ( a[key] != 0 )      length = 0 ;
      }   
     
      return max ;
      
    }
};
