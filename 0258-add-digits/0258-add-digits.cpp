class Solution {
private:
    int digitSum(int num) {
        int ans = 0; 
        int n = num; 
        
        while (n > 0) {
            
            int temp = (n % 10);
            ans += temp; 
            n /= 10; 
            
        }
        return ans; 
    }
public:
    int addDigits(int num) {
        if(num == 0)return 0;
        int totalDigits = (log10(num) + 1); 
       
        int n = num; 
        while (totalDigits > 1) {
            n = digitSum(n); 
            
            totalDigits = floor(log10(n) + 1);   
            
        }
        
        return n; 
        
    }
};