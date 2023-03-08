class Solution {
private: 
    bool isPossible(vector<int>& piles, int h, int ans) {
        int size = piles.size(); 
        
        int hrs = 0; 
        for (int i = 0; i < size; i++) {
            hrs += ceil(piles[i] / (ans * 1.0)) ;
            
            if (hrs > h)
                return false; 
        }
        // cout << hrs << " "; 
        if (hrs > h)
            return false; 
    
        return true; 
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 0, high = INT_MIN; 
        for (int i = 0; i < n; i++) {
            high = max(high, piles[i]); 
        }
        // cout << low << " " << high << endl; 
        
        while ((high - low) > 1) {
            int mid = low + (high - low ) / 2; 
            
            if (isPossible(piles, h, mid)) 
                high = mid; 
            else 
                low = mid; 
        }
        return high; 
    }
};