class Solution {
private: 
    // memoisation :
    int lcs(string s1, string s2, int m, int n, vector<vector<int>> &dp) {
        
        if (m == 0 || n == 0) {
            return 0; 
        }
        if (dp[m][n] != -1)
            return dp[m][n]; 
        
        if (s1[m-1] == s2[n-1]) {
            return dp[m][n] = 1 + lcs(s1, s2, m-1, n-1, dp); 
        }
        
        int first = lcs(s1, s2, m-1, n, dp); 
        int second = lcs(s1, s2, m, n-1, dp); 
        
        return dp[m][n] = max(first, second); 
    }
public:
    int minInsertions(string s) {
        int n = s.length(); 
        // tabulation :
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); 
        string rev = s;
        reverse(rev.begin(), rev.end());
        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=n; j++){
                if(i == 0 or j == 0)dp[i][j] = 0;
                else{ 
                    if(s[i-1] == rev[j-1])dp[i][j] = 1 + dp[i-1][j-1];
                    else{
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }      
        }
        }
                      
        return  n - dp[n][n];  
    }
};