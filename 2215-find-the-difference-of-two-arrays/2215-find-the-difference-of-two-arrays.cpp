class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2); 
        
        unordered_set<int> temp1, temp2; 
        unordered_set<int> st1, st2; 
        for (auto it : nums1) {
            st1.insert(it); 
        }
        for (auto it : nums2) 
            st2.insert(it); 
        
        for (auto it : nums1) {
            if (st2.find(it) == st2.end()) {
                temp1.insert(it);
            }
        }
        for (auto it : nums2) {
            if (st1.find(it) == st1.end()) {
                temp2.insert(it); 
            }
        }
        vector<int> t1(temp1.begin(), temp1.end()), t2(temp2.begin(), temp2.end()); 
        
        ans[0] = t1, ans[1] = t2; 
        
        return ans; 
    }
};