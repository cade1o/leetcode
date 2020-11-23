class Solution {
public:
    int romanToInt(string s) {
        
        int temp=0 ,key = 0 ;
        int out= 0 ;
        map<char,int> rom ;
        
        rom['I']=1;
        rom['V']=5;
        rom['X']=10;
        rom['C']=100;
        rom['L']=50;
        rom['D']=500;
        rom['M']=1000;
        
        if ( s.length() == 1 ) return rom[s[0]] ;
        
        key = rom[s[s.length()-1]] ;
        
        for ( int i = 0 ; i < s.length() ; i ++ )
        {
            if ( rom[s[s.length()-1-i]] >= key ) 
            {
                out += rom[s[s.length()-1-i]] ;
                key = rom[s[s.length()-1-i]] ;
            }
            else out -=rom[s[s.length()-1-i]] ; 
        }
        return out ;
    }
};
