class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1; 
        
        for (int i = 0, j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                nums[++i] = nums[j]; 
                k++; 
            }
                
        }
        return k; 
    }
};