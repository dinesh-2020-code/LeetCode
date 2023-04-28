//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        vector<vector<int>> ans (n, vector<int>(m, 1e9)); 
        
        queue<pair<int, int>> q; 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (c[i][j] == 'W') {
                    q.push({i, j}); 
                    ans[i][j] = 0; 
                }
            }
        }
        
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        
        while (!q.empty()) {
            auto curr = q.front(); 
            q.pop(); 
            
            int _x = curr.first; 
            int _y = curr.second; 
            
            for (int i = 0; i < 4; i++) {
                int new_x = _x + dx[i]; 
                int new_y = _y + dy[i]; 
                
                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && c[new_x][new_y] != 'N' && ans[new_x][new_y] > ans[_x][_y] + 1) {
                    q.push({new_x, new_y}); 
                    ans[new_x][new_y] = ans[_x][_y] + 1; 
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (c[i][j] == '.') 
                    ans[i][j] = 0; 
                    
                else if (ans[i][j] == 1e9 && c[i][j] != 'N') 
                    ans[i][j] = -1; 
                else if (ans[i][j] == 1e9 && c[i][j] != 'H') {
                    ans[i][j] = 0; 
                }
                else {
                    ans[i][j] *= 2; 
                }
            }
        }
        
        return ans; 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends