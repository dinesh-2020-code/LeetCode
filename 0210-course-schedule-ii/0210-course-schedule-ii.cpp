class Solution {
public:
    
    void print(vector<int> adj[], int V) {
        
        for(int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (auto it : adj[i]) {
                cout << it << " "; 
            }
            cout << endl; 
        }
    }
    void printVec(vector <int> &v) {
        for (auto it : v) {
            cout << it << " "; 
        }
        cout << endl; 
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans; 
        
        vector<int> adj[numCourses]; 
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            
            adj[u].push_back(v); 
        }
        print(adj, numCourses);
        vector<int> indegree(numCourses, 0);
        
        //calculating the indegrees
        for (int i = 0; i < numCourses; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                indegree[adj[i][j]]++; 
            }
        }
        printVec(indegree); 
        
        //Topo sort using Kahn's algo
        
        
        queue<int> q; 
    
        //enqueue all 0 indegree vertices 
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i); 
        }
        
        while (!q.empty()) {
            int node = q.front(); 
            q.pop(); 
            ans.push_back(node); 
            for (int it : adj[node]) {
                indegree[it]--; 
                
                if (indegree[it] == 0)
                {
                    q.push(it); 
                    
                }
            }
            
        }
        
        printVec(ans); 
        return (ans.size() == numCourses) ? ans : vector<int> {};
    
    }
};