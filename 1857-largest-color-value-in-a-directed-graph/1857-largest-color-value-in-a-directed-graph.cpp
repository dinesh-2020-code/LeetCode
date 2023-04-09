class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        int n = colors.size(); 
        //creating adjacency list
        vector<int> adj[n]; 
        vector<int> indegree(n, 0); 
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0]; 
            int v = edges[i][1]; // edge is from u to v
            adj[u].push_back(v); 
            indegree[v]++; 
        }
        queue<int> zero_indegree; 
        //Pushing all the top nodes i.e., the nodes with indegree 0
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                zero_indegree.push(i); 
            }
        }

        vector<vector<int>> counts(n, vector<int>(26, 0)); //array of count[n][26] for 1 node 26 colors is possible, so for n nodes 26 * n colors possible
        for (int i = 0; i < n; i++) {
            counts[i][colors[i] - 'a']++; 
        }

        int max_count = 0, visited = 0; 
        while (!zero_indegree.empty()) {
            int u = zero_indegree.front(); 
            visited++; 
            zero_indegree.pop(); 

            for (int v : adj[u]) {
                for (int i = 0; i < 26; i++) {
                    counts[v][i] = max(counts[v][i], counts[u][i] + (colors[v] - 'a' == i ? 1 : 0)); 
                }
                indegree[v]--; 
                if (indegree[v] == 0) {
                    zero_indegree.push(v); 
                }
            }
            max_count = max(max_count, *max_element(counts[u].begin(), counts[u].end()));

        }
        return (visited == n ? max_count : -1); 








    }
};