class Leaderboard {
public:
    unordered_map<int,int> board;
  
    static bool com( pair<int,int>&a, pair<int,int>&b){
        return a.second > b.second;
    }
    
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        if( board.find(playerId) == board.end() ) {
            board[playerId] = score;
        }
        else board[playerId]+= score;
    }
    
    int top(int K) {
        int sum = 0, i = 0;
        vector<pair<int,int>> b;
        for(auto a:board) b.push_back({a.first, a.second});
        
        sort(b.begin(), b.end(), com);
        for(auto a: b) {
            i++;
            sum+=a.second;
            if( i == K) break;
        }
        return sum;
    }
    
    void reset(int playerId) {
        board[playerId] = 0;
    }
};
​
/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
