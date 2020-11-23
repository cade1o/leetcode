       
       Maximize l[i]+m[i+M] for i>=L
       
       //THE ABOVE CASE IS FRIST CHOSING L SIZE ARRAY THEN CHOOSING M SIZE ARRAY
       
       //RUN ITS REVERSE PROCESS ALSO
    */
            
        
        for(int i=L;i<=n;i++)
            l[i]=A[i]-A[i-L];
        
        for(int i=M;i<=n;i++)
            m[i]=A[i]-A[i-M];
        
        
        for(int i=1;i<=n;i++){
            l[i]=max(l[i],l[i-1]);
        }   
        for(int i=n-1;i>=0;i--){
            m[i]=max(m[i],m[i+1]);
        }
        
        int Max=0;
        for(int i=L;i<=n;i++){
            if(i+M<=n)
                Max=max(Max, l[i]+m[i+M]);
        }
        
        
        for(int i=0;i<=n;i++)
        {
            l[i]=0;
            m[i]=0;
        }
        for(int i=L;i<=n;i++)
            l[i]=A[i]-A[i-L];
        
        for(int i=M;i<=n;i++)
            m[i]=A[i]-A[i-M];
        
        for(int i=1;i<=n;i++){
            m[i]=max(m[i],m[i-1]);
        }   
        for(int i=n-1;i>=0;i--){
            l[i]=max(l[i],l[i+1]);
        }
        
        for(int i=M;i<=n;i++){
            if(i+L<=n)
                Max=max(Max, m[i]+l[i+L]);
        }
        return Max;
    }
};
