class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size(), m = queries.size(); 
        
        vector<long long> ans(m); 
        vector<long long int> prefSum(n); 
        prefSum[0] = (long long)(nums[0]); 
            
        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i-1] + (long long) nums[i]; 
        }
        
        for (long long int j = 0; j < m; j++) {
            long long int x = (long long)queries[j];
            
            int i = lower_bound(nums.begin(), nums.end(), x) - nums.begin();  // returns index of element >= x
            
            long long largerSum = (i-1 >= 0) ? ( prefSum[n-1] - prefSum[i-1]) : prefSum[n-1]; 
            long long smallerSum = (i-1 >= 0)? prefSum[i-1]: 0; 
            
            long long incReq = (1LL * x * i - smallerSum);
            long long decReq = largerSum - (1LL * x * ((long long)n - i));
            
            ans[j] = incReq + decReq; 
            
            
        }
         
        return ans; 
    }
};