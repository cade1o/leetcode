class Solution {
public:
    double knightProbability(int n, int k, int r, int c) {
        if(n==1){
            if(k==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        double dp[k+1][n][n];
        memset(dp, 0, sizeof(dp));
        dp[0][r][c] = 1;
        double off = 0;
        vector<pair<int, int> > moves({{2,1},{1,2},{-2,1},{1,-2},{-1,2},{2,-1},{-2,-1},{-1,-2}});
        for(int move = 1; move<=k; move++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dp[move-1][i][j]>0){
                        for(pair<int, int> p: moves){
                            int a = i+p.first;
                            int b = j+p.second;
                            if(a>=0 && b>=0 && a<n && b<n){
                                dp[move][a][b]+=dp[move-1][i][j];
                            }
                            else{
                                off += dp[move-1][i][j]/8;
                            }
                        }
                    }
                }
            }
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    dp[move][i][j]/=8.0;
                }
            }
        }
        return 1-off;
    }
};
