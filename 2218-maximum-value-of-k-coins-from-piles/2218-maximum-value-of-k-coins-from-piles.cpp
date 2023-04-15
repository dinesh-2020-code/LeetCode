class Solution {
private: 
    int solve(int ind, int k, vector<vector<int>>& piles, vector<vector<int>>& dp) {
        
        if (ind == piles.size() || k == 0) 
            return 0; 
        
        //do not take the coin from ith pile
        if (dp[ind][k] != -1)
            return dp[ind][k]; 
        int res = solve(ind+1, k, piles, dp); 
        int curr = 0; 
        //take the coins from ith pile
        
        for (int j = 0; j < piles[ind].size() && j < k; j++) {
            curr += piles[ind][j]; 
            res = max(res, solve(ind + 1, k - j - 1, piles, dp) + curr); 
            
        }
        return dp[ind][k] = res; 
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size(); 
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1)); 
        
        
        return solve(0, k, piles, dp); 
        
    }
};