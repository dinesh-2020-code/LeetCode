class Solution {
public:
    string intToRoman(int num) {
        string ans = ""; 
        
        string M[] = {"","M","MM","MMM"};
        string C[] = {"", "C", "CC", "CCC", "CD", "D","DC","DCC","DCCC","CM","M"};
        string I[]  = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string X[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        
        ans = M[(num / 1000)] + C[(num % 1000) / 100] + X[(num % 100)/10] + I[num % 10];
                                                           
                                                           return ans; 
        

    }
                                                           };
    