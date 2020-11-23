                if ( equations[i][1] == equations[j][1] )
                {
                    for ( int k = 0 ; k < equations.size() ; k++ )
                    {
                       if ( equations[i][0] == equations[k][0] && equations[j][0] == equations[k][1] )p = 1 ;
                    }
                    if ( p != 1 )
                    {
                        equations.push_back({equations[i][0],equations[j][0]}) ;
                        if ( equations[i][0] != equations[j][0] )
                        values.push_back({values[i]/values[j]}) ;
                        else values.push_back( 1.00000) ;
                    }
                }
           }    
       }
        
       int f ;
       
       for ( int i = 0 ; i < queries.size() ; i ++ )
       {
           f = 0 ;
           for ( int j = 0 ; j < equations.size() ; j ++ )
           {
                if ( queries[i][0] == equations[j][0] && queries[i][1] == equations[j][1] ) 
                {
                    f = 1 ;
                    out.push_back( values[j] ) ;
                    break ;
                }
               
               if ( queries[i][0] == equations[j][1] && queries[i][1] == equations[j][0] ) 
                {
                    f = 1 ;
                    out.push_back( 1/values[j] ) ;
                    break ;
                }
              
                if ( queries[i][0] == queries[i][1] && queries[i][1] == equations[j][0] || queries[i][0] == queries[i][1] && queries[i][1] == equations[j][1] ) 
                {
                    f = 1 ;
                    out.push_back( 1.00000 ) ;
                    break ;
                }
           }
           
           if ( f == 0 ) out.push_back(-1.00000) ;
       }
        
       return out ;
    }
};
