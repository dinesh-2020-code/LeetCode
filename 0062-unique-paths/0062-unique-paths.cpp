class Solution {
private: 
    int paths(int x, int y, int m, int n, vector<vector<int>> &vis,vector<vector<int>> &dp) {
        vis[x][y] = 1; 
        if (x == m-1 && y == n-1) {
            vis[x][y] = 0; 
            return 1; 
        }
        if (dp[x][y] != -1) {
            return dp[x][y]; 
        }
        int down = 0, right = 0; 
        if (x+1 >= 0 && x+1 < m && y >= 0 && y < n &&  !vis[x+1][y])
        {
            down = paths(x+1, y, m, n, vis, dp); 
        }
        if (x >= 0 && x < m && y+1 >= 0 && y+1 < n &&  !vis[x][y+1]) {
            right = paths(x, y+1, m, n, vis, dp); 
        }
        
        vis[x][y] = 0; 
        return dp[x][y] = (down + right); 
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> vis (m, vector<int>(n, 0)); 
        vector<vector<int>> dp(m, vector<int>(n, -1)); 
        return paths(0,0,m, n, vis, dp); 
    }
};