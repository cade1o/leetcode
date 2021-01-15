class Solution {
public:
    bool isRobotBounded(string instructions) {
        int spin = 0 , dir = 0 , x = 0 , y = 0;
                
        for( char a : instructions ){
            
            if( a == 'G' ) {
                if( dir == 0 ) y++ ;
                if( dir == 1 ) x++ ;
                if( dir == 2 ) y-- ;
                if( dir == 3 ) x-- ;
            }
            if ( a == 'L' ) { 
                spin++ ;
                dir-- ;
                if( dir < 0 ) dir = 3 ;
            }
                             
            if ( a == 'R' ) {
                spin-- ;
                dir++ ;
                if( dir == 4 ) dir = 0 ;
            }
        }
        if( x == 0 && y == 0 ) return 1 ;
        
        if( spin % 4 == 0 || spin == 0 ) return false ;
        else return true ;
    }
};
