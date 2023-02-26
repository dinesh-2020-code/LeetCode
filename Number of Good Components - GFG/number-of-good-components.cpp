//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<vector<int>> & adj, vector<int> &vis) {
        
        vis[node] = 1; 
        
        for (auto it : adj[node]) {
            if (!vis[it]) 
                dfs(it, adj, vis); 
        }
    }
    void print(vector<vector<int>> &adj, int V) {
       for (int i = 1; i <= V; i++) {
            // cout << it << ": "  ;
            for (auto k : adj[i]) {
                cout << k << " "; 
            }
            cout << "\n"; 
        }
    }
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        
        vector<int> components; 
        vector<int> vis(V+1, 0);
        
        
        for (int i = 1; i <= V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis);
                components.push_back(i); 
            }
        }
        // cout << components.size() << endl;
        
        // for (int i = 0; i < components.size(); i++)
        //     cout << components[i] << " "; 
        //     cout << endl; 
        int ans = 0; 
        for (int i = 1; i <= V; i++) {
            adj[i].push_back(i); 
            sort(adj[i].begin(), adj[i].end()); 
        }
        // print(adj, V); 
        
        for (auto it : components) {
            bool flag = true; 
            vector<int> v1 = adj[it];
            for (auto x : adj[it]) {
                vector<int> v2 = adj[x]; 
                if (v1 != v2)
                {
                    flag = false; 
                    break; 
                }
            }
            if (flag)
                ans++; 
            
        }
        
        return ans; 
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends