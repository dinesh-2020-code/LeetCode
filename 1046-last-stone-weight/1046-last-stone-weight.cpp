class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int ans = 0; 
        
        priority_queue<int> pq; 
        for (auto it : stones) {
            pq.push(it); 
        }
        
        while (!pq.empty()) {
            if (pq.size() == 1) {
                break; 
            }
            int stone1 = pq.top(); pq.pop(); 
            int stone2 = pq.top(); pq.pop();
            
            if (stone1 != stone2) {
                stone1 -= stone2; 
                pq.push(stone1); 
            }
            
        }
        if (!pq.empty()) 
            ans = pq.top(); 
        
        return ans; 
        
    }
};