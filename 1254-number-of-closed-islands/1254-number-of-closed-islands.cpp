class Solution {
private: 
    bool isValid(int row, int col, int n, int m, vector<vector<int>>& grid) {
        if (row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == 0) {
            return true; 
        }
        return false; 
    }
    void dfs(int row, int col, int n, int m, vector<vector<int>>& grid) {
        grid[row][col] = 1; 
       
        int dx[4] = {1, -1, 0, 0}; 
        int dy[4] = {0, 0, 1, -1};
        
        for (int i = 0; i < 4; i++) {
            int newRow = row + dx[i]; 
            int newCol = col + dy[i]; 
            
            if (isValid(newRow, newCol, n, m, grid)) {
                dfs(newRow, newCol, n, m, grid); 
            }
        }
        
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size(); 
        int m = grid[0].size(); 
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i * j == 0 || i == n - 1 || j == m - 1) {
                    if (grid[i][j] == 0)
                        dfs(i, j, n, m, grid); 
                }
            }
        }
        
        int ans = 0; 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    ans++; 
                    dfs(i, j, n, m, grid); 
                }
            }
        }
        
        return ans; 
    }
};