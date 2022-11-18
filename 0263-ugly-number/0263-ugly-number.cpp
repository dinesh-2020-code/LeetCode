class Solution {
public:
    bool isUgly(int n) {
        if (n <=  0)
            return false; 
        while (n % 2 == 0) {
            n /= 2;
        }
        
        for (int i = 3; i <= sqrt(n); i += 2) {
            
            while (n % i == 0) {
                cout << i << endl;
                if (i > 5) {
                    
                    return false;
                }
                     
                
                n /= i;
            }
        }
        if (n > 5) {
            return false; 
        }
        return true; 
        
    } 
};