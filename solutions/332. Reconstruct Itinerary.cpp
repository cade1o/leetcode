class Solution {
public:
    vector<string> out ;
    vector<string> output ;
    unordered_map<string,int> visited;
    string s ;
    int size ,end = 0 ;
   
    vector<string> findItinerary(vector<vector<string>>& tickets) {
​
        unordered_map<string,vector<string>> graph;
        
        size = tickets.size() ;
        for( int i = 0 ; i < tickets.size() ; i++ )
        {
            s = tickets[i][0] + tickets[i][1] ;
            if ( visited.count(s) > 0 )
            visited[s] ++ ;
            else visited[s] = 1 ;
            graph[tickets[i][0]].push_back(tickets[i][1]);     
        }
       
        for ( auto&a : graph)
        {
            sort(a.second.begin(),a.second.end()) ;
        }
        
        dfs(graph,"JFK", size, out) ;
​
        return output;
    }
    
    void dfs(unordered_map<string,vector<string>> graph, string node, int size, vector<string>& out )
    {
​
        if ( end == 1 ) return ;
        
        out.push_back(node) ;
        if ( out.size() == size + 1 ) 
        {
            output = out ;
            end = 1 ;
            return ;
        }
        
        for( auto i = 0 ; i < graph[node].size() ; i++ )
        {
            s = node + graph[node][i] ;
            if ( visited[s] != 0)
            {
                visited[s]-- ;
                dfs(graph, graph[node][i], size, out) ; 
            }
        }
        
        s = out[out.size()-2] + out[out.size()-1] ;
        visited[s] ++ ;
        
        if( out.size() > 1 )
        out.erase(out.end()-1) ;
 
        return ;
    } 
};
