class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int res = nums[0], maxEnding = nums[0], n = nums.size(); 
        
        for (int i = 1; i < n; i++) 
        {
            maxEnding = max(maxEnding + nums[i], nums[i]); 
            res = max(res, maxEnding); 
        }
        return res; 
        
    }
};