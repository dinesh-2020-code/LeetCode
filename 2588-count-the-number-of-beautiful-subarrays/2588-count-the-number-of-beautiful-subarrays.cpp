class Solution {
public:
    void print(vector<long long > v) {
        for (auto it : v)
            cout << it << " "; 
        cout << endl; 
    }
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size(); 
        
        if (n == 1 && nums[0] == 0)
            return 1; 
        long long ans = 0;
        vector<long long > pref(n);
        pref[0] = 1LL * nums[0]; 
        
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] ^ (1LL * nums[i]); 
        }
        unordered_map<long long, int> mp; 
        mp[0] = 1; 
        for (auto it : pref) {
            if (mp[it]) {
                 ans += mp[it]; 
                mp[it]++; 
               
            }
            else {
                mp[it]++; 
            }
        }
        
        // print(pref);
        return ans; 
        
        
        
    }
};