class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size(); 
        int small = INT_MAX, big = INT_MAX;
        
        for (auto i : nums) {
            if (i <= small)
                small = i;
            else if (i <= big)
                big = i; 
            else 
                return true; 
        }
        
        return false;
    }
};