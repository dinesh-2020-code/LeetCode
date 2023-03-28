class Solution {
    bool check(vector<int> &weights, int days, int ans) {
        
        int d = 1; 
        int currWt = 0; 
        
        for (int i = 0; i < weights.size(); i++) {
            if (currWt + weights[i] <= ans) {
                currWt += weights[i]; 
            }
            else {
                d++; 
                currWt = weights[i]; 
            }
        }
        
        return (d <= days);   //if no of days is less than or equal to given number of days
    }
public:
    
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = INT_MIN, sum = 0; 
        int n = weights.size(); 
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, weights[i]); 
            sum += weights[i]; 
        }
        
        int low = maxi;   // if all packages to be delivered in one day
        int high = sum; 
        
        while (low <= high) {
            
            int mid = low + (high - low) / 2; 
            
            if (check(weights, days, mid)) {
                high = mid-1; 
            }
            else {
                low = mid+1; 
            }
        }
        return low; 
        
    }
};