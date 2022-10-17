class Solution {
public:
    int i = 0;
    string res = ""; 
    void solve(map<string, int> &mp, string &ans, int n) {
        //base case 
        if (ans.size() == n) {
            if(mp[ans] == 0) {
                res = ans;
                i = 1; 
            }
            return; 
        }
        if (i) 
            return; 
        
        ans.push_back('0'); 
        solve(mp, ans, n);
        ans.pop_back(); 
        
        ans.push_back('1');
        solve(mp, ans, n); 
        ans.pop_back(); 
        
    }
    string findDifferentBinaryString(vector<string>& nums) {
        map<string, int> mp; 
        
        for (auto i : nums) {
            mp[i] = 1;
        }
        
        
        string ans = ""; 
        int n = nums[0].size(); 
        solve(mp,ans,n); 
        return res; 
    }
};