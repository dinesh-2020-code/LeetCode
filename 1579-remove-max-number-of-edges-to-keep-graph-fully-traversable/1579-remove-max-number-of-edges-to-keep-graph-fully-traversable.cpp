class UnionFind {
    vector<int> rank; //representative array -> gives the height of the tree 
    vector<int> parent; 
    int components; 
    
public : 
   
    UnionFind(int n) {
        components = n; 
        
        for (int i = 0; i <= n; i++) {
            rank.push_back(0);
            parent.push_back(i); 
        }
    }
    
    //Find the representative of the node
    
    int findRepresentative(int x) {
        if (x == parent[x])  // 
            return x; 
        
        
        //Path compression
        parent[x] = findRepresentative(parent[x]); 
        return parent[x];
    }
    
    //Union
    
    int performUnion(int x, int y) {
        int x_rep = findRepresentative(x); 
        int y_rep = findRepresentative(y); 
        
        if (x_rep == y_rep)
            return 0; 
        
        if (rank[x_rep] < rank[y_rep]) {
            parent[x_rep] = y_rep; 
        }
        else if (rank[y_rep] < rank[x_rep]) {
            parent[y_rep] = x_rep;
        } 
        else {
            parent[y_rep] = x_rep; 
            rank[x_rep]++; 
            
        }
        components--; 
        return 1; 
    }
    
    bool isConnected() {
        return (components == 1);
    }
          
}; 

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        //different components for Alice and Bob
        UnionFind Alice(n), Bob(n); 
        
        int edgesReq = 0; 
        
        
        //Perform union of edges of type 3, for both ALice and Bob
        for (vector<int> &edge: edges) {
            if (edge[0] == 3) {
                edgesReq += (Alice.performUnion(edge[1], edge[2]) | Bob.performUnion(edge[1], edge[2])); 
            }
        }
        
        // Perform union for Alice if type = 1 and for Bob if type = 2.
        
        for (vector<int> &edge : edges) {
            if (edge[0] == 1) {
                edgesReq += Alice.performUnion(edge[1], edge[2]); 
            }
            else if (edge[0] == 2) {
                edgesReq += Bob.performUnion(edge[1], edge[2]);
            }
        }
        
        if (Alice.isConnected() && Bob.isConnected()) {
            return edges.size() - edgesReq; 
        }
        return -1; 
    }
};