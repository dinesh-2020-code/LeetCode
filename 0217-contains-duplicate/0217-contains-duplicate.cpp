class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st; 
        for (auto i : nums)
            st.insert(i); 
        
        return (st.size() == nums.size()) ? false : true; 
    }
};