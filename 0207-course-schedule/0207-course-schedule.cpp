class Solution {
    
    void print(vector<int> adj[], int n) {
        for (int i = 0; i < n; i++) {
            cout << i << ": "; 
            for (auto x : adj[i]) {
                cout << x << " "; 
            }
            cout << endl; 
            
        }
    }
    void printVec(vector<int> v) {
        for (auto it : v) {
            cout << it << " ";
        }
        cout << endl; 
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         
        vector<int> adj[numCourses];
        vector<int> indegrees(numCourses, 0); 
        for (int i = 0; i < prerequisites.size(); i++) 
        {
            int u = prerequisites[i][1]; 
            int v = prerequisites[i][0]; 
            //u -> v is an edge
            indegrees[v]++; 
          
            adj[u].push_back(v); 
        
        }
        print(adj, numCourses); 
        printVec(indegrees);
        
        queue<int> q;
        int count = numCourses; 
        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0) {
                q.push(i); 
                count--; 
            }
        }
        
        
        while (!q.empty()) {
            
            int course = q.front(); 
            q.pop();
            
            for (auto it : adj[course]) {
                indegrees[it]--; 
                
                if (indegrees[it] == 0) {
                    q.push(it); 
                    count--; 
                }
            }
            
            
        }
        
        return (count == 0) ? true : false; 
        
        
        
    }
};

/*
    6
    [[2, 0], [3,0], [1,2], [1,3], [4,2], [5,4], [5,3]]
    
    [ai, bi] : ai <- bi 
    
    Adjacency Matrix: 
        -> takes more space
        -> takes extra space
        -> 
    
    */