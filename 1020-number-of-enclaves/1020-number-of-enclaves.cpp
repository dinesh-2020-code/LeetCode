class Solution {
private: 
    bool isValid(int row, int col, int m, int n, vector<vector<int>> &grid) {
        if (row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 1) {
            return true;
        }
        return false; 
    }
    void dfs(int row, int col, int m, int n, vector<vector<int>> &grid) {
        
        grid[row][col] = 0; 
        
        int dx[] = {1, -1, 0, 0}; 
        int dy[] = {0, 0, 1,-1};
        
        for (int i = 0; i < 4; i++) {
            int newRow = row + dx[i]; 
            int newCol = col + dy[i]; 
            
            if (isValid(newRow, newCol, m, n, grid)) {
                dfs(newRow, newCol, m, n, grid); 
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size(); 
        int n = grid[0].size(); 
        
        //marking all the  land that is reachable from boundary to sea
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i * j == 0 || i == m - 1 || j == n - 1) {  //boundary conditions
                    if (grid[i][j] == 1) {
                        dfs(i, j, m, n, grid); 
                    }
                }
            }
        }
        
        int ans = 0; 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ans++; 
                }
            }
        }
        return ans; 
    }
};