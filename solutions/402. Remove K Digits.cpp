class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int i=0, n=num.length();
        stack<char> s;
        string str="";
        
        while(k>0 && i<n){
            
            if(s.empty()) s.push(num[i]);
            else{
                
                while(!s.empty() && s.top()>num[i] && k>0){
                    s.pop(); k--;
                }
                s.push(num[i]);
            }
            i++;
        }
        while(i<n){
            s.push(num[i]); i++;
        }
        
        while(!s.empty()){
            str+=s.top();
            s.pop();
        }
        
        i=0;
        reverse(str.begin(), str.end());
        while(str[i]=='0') i++;
        str=str.substr(i);
        
        str=str.substr(0, str.length()-k);
        if(str.length()==0) return "0";
        else return str;
       
    }
};
