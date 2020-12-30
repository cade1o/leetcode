class Solution {
public:
    unordered_map<int,string> number;
    
    string convert1to999(int a){
        string temp = "" ;
        if ( a/100 > 0 ) 
        {
            temp+= " ";
            temp+= number[a/100] + " Hundred" ;
        }
        a = a % 100 ;
        if ( a/10 == 1 ) 
        {
            temp+= " ";
            temp+= number[a] ;
            return temp ;
        }
        else
        {
            if ( a/10 > 1 )
            {
                temp+= " ";
                temp+= number[a/10*10] ;
            }
        }
        a = a % 10 ;
        if ( a > 0 ) 
        {
            temp+= " ";
            temp+= number[a] ;
        }
        return temp ;
    }
    
    string numberToWords(int num) {
        
        if (num == 0 ) return"Zero" ;
       
        int bil = 0, mil = 0, thou = 0, hun = 0, left = 0 ;
        number[1] = "One" ;
        number[2] = "Two" ;
        number[3] = "Three" ;
        number[4] = "Four" ;
        number[5] = "Five" ;
        number[6] = "Six" ;
        number[7] = "Seven" ;
        number[8] = "Eight" ;
        number[9] = "Nine" ;
        number[10] = "Ten" ;
        number[11] = "Eleven" ;
        number[12] = "Twelve" ;
        number[13] = "Thirteen" ;
        number[14] = "Fourteen" ;
        number[15] = "Fifteen" ;
        number[16] = "Sixteen" ;
        number[17] = "Seventeen" ;
        number[18] = "Eighteen" ;
        number[19] = "Nineteen" ;
        number[20] = "Twenty" ; 
        number[30] = "Thirty" ;
        number[40] = "Forty" ;
        number[50] = "Fifty" ;
        number[60] = "Sixty" ;
        number[70] = "Seventy" ;
        number[80] = "Eighty" ;
        number[90] = "Ninety" ;
        
      
        string out = "";
        bil = num / 1000000000 ;
        mil = num / 1000000 ;
        thou = num / 1000 ; 
        hun = num / 100 - thou*10;
        left = num % 100 ;
        
        if (num%1000000000 == 0) return number[bil]+" Billion" ;
