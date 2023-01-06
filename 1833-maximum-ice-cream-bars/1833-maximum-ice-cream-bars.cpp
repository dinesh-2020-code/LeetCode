class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans = 0; 
        
        sort(costs.begin(), costs.end()); 
        if (coins < costs[0])
            return ans; 
        int cost = 0; 
        for (int i = 0; i < costs.size()  && (cost + costs[i]) <= coins; i++) {
            ans++; 
            cost += costs[i]; 
        }
        return ans; 
    }
};