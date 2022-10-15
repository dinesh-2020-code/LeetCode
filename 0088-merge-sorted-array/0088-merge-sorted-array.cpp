class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> temp; 
        
        int i = 0, j = 0; 
        
        for (; i < m && j < n ;) {
            if (nums1[i] <= nums2[j]) {
                temp.emplace_back(nums1[i]); 
                i++; 
            }
            else {
                temp.emplace_back(nums2[j]); 
                j++; 
            }
        }
        
        if (i < m) {
            for (; (i < m); i++) {
                temp.push_back(nums1[i]);
            } 
        }
        
        if (j < n) {
            for (; (j < n); j++) {
                temp.push_back(nums2[j]);
            } 
        }
        
        i = 0;
        j = 0;
        for (auto it : temp) {
            cout << it << " ";
        }
        for (; i < (m + n);)
        {
            nums1[i++] = temp[j++];
        }
                
    }
};