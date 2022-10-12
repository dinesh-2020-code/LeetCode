class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(); 
        int a = 0, b = 0, c = 0; 
        int sum = 0; 
        for (int i = n - 1; i >= 2; i--) {
            a = nums[i]; 
            b = nums[i - 1]; 
            c = nums[i - 2]; 
            
            if (b + c > a) {
                sum = (a + b + c); //perimeter of triangle
                break; 
            }
                
        }
        return sum; 
    }
    
};