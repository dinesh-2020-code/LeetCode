class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans = 0; 
        
        ans += (numOnes - k ) >= 0 ? (k * 1) : (numOnes);
        k -= numOnes; 
        if (k <= 0)
           return ans;       
        
        k -= numZeros;
        
        if (k <= 0)
            return ans;     
        
        ans += (numNegOnes - k) >= 0 ? ( k * -1 ) : 0; 
        
        return ans;  
    }
};