class Solution {
    void solve(vector<int> &arr, vector<vector<int>> &ans, int index) {
        
        if (index >= arr.size()){
            ans.push_back(arr); 
            return; 
        }
        
        for (int i = index; i < arr.size(); i++) {
            swap(arr[i], arr[index]); 
            solve(arr, ans, index + 1);
            swap(arr[i], arr[index]); 
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; 
        vector<int> output; 
        solve(nums, ans,  0); 
        return ans; 
    }
};