class Solution {
public:
    bool issubseq(string in, string source){
        if( in.size() > source.size() ) return 0;
        int del = 0;
        
        for( int i = 0, j = 0; i< source.size() ;i++){
            if( source[i] != in[j] ) del++;
            else j++;
        }
        if( del == source.size() - in.size() ) return 1;
        
        return 0;
    }
    int shortestWay(string source, string target) {
        unordered_set<char> count;
        
        for(char a: source) count.insert(a);
        for(char a: target) if( count.count(a) == 0) return -1;
        
        int l = 1, st = 0, res = 0;
        
        for( int i = 0; i < target.size() ; ++i){
      
            if( issubseq(target.substr(st,l), source) == 1) {
                l++;
                if( st+l == target.size() ) res++;
            }
            else {
                res++;
                st = i;
                l = 1;
                i--;
            }
        }
        
        return res;
        
    }
};
