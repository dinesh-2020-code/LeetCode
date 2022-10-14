class Solution {
public:
    int totalMoney(int n) {
        
        int completeWeeks = n / 7; 
        int remDays = n % 7; 
        int a = 1, sum = 0, temp = 0; 
        while (completeWeeks--) {
            temp = (7 * ((2 * a) + 6)) / 2; //Sum of N terms of AP with first term 'a' and common difference 'd=1' and 'n=7'
            
            sum += temp; 
            
            a++; 
            
        }
        
        temp = (remDays * ((2 * a) + (remDays - 1))) / 2; 
                
        sum += temp; 
                
        return sum; 
        
    }
};