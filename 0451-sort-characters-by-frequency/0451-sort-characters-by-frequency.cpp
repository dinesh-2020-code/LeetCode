class Solution {
public:
    static bool cmp (int a, int b) {
        return (a > b) ? true: false; 
    }
    string frequencySort(string s) {
        unordered_map<char, int> mp; 
        
        for (auto i : s) 
            mp[i]++; 
        
        vector<pair<int, char>> vp; 
        
        string ans = ""; 
        for (auto i : mp) {
            pair<int, char> p(i.second, i.first);
            vp.push_back(p);
            // cout << i.first << ": " << i.second << endl; 
        }
        sort(vp.rbegin(), vp.rend());
        for(auto it : vp) {
            int t = it.first;
            while (t--) {
                ans += it.second; 
            }
            // cout << it.first << " : " << it.second << endl; 
        }
        
        return ans; 
    }
};