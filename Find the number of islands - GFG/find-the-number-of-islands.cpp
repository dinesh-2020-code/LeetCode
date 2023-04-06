//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private: 
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int x, int y) {
        int n = grid.size(), m = grid[0].size(); 
        vis[x][y] = 1; 
        
        queue<pair<int, int>> q; 
        q.push({x, y}); 
        
        while (!q.empty()) {
            int row = q.front().first; 
            int col = q.front().second; 
            q.pop(); 
            
            //traverse and mark if it is a land
            
            for (int delRow = -1; delRow <= 1; delRow++) {
                for (int delCol = -1; delCol <= 1; delCol++) {
                    int newRow = row + delRow; 
                    int newCol = col + delCol; 
                    
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == '1' && !vis[newRow][newCol]) {
                        
                        vis[newRow][newCol] = 1; 
                        q.push({newRow, newCol}); 
                    }
                }
            }
            
            
        }
    }
  
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0; 
        
        int n = grid.size(), m = grid[0].size(); 
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    bfs(grid, vis, i, j);
                    ans++; 
                }
            }
        }
        
        return ans; 
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends