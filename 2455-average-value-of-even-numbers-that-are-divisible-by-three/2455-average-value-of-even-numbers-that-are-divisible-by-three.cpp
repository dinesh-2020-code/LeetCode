class Solution {
public:
    int averageValue(vector<int>& nums) {
        int ans = 0, sum = 0; 
        
        int n = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0 and nums[i] % 3 == 0)
            {
                sum += nums[i];
                n++; 
            }
        }
        if (n != 0)
            ans = sum / n; 
        return ans; 
    }
};

//[1,3,6,10,12,15]