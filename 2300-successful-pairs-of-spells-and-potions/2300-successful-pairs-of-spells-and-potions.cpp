class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size(); 
        vector<int> ans(n); 
        
        sort(potions.begin(), potions.end());  
        
        for (int i = 0; i < n; i++) {
            
            int low = 0, high = m -1; 
            int spell = spells[i]; 
            while (low <= high) {
                int mid = low + (high - low) / 2; 
                
                if (1LL * spell * potions[mid] >= success) {
                    high = mid - 1; 
                }
                else {
                    low = mid + 1; 
                }
            }
            
            ans[i] = m - low; 
        }
        
        return ans; 
        
    }
};