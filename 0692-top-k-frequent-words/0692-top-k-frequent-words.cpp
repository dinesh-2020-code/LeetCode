class Solution {
public:
    static bool cmp (const pair<string, int> &p1, const pair<string, int> &p2) {
        if (p1.second == p2.second) {    //if frequency is same then sort lexicographically
            return (p1.first < p2.first);
        }
        return (p1.second > p2.second);
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans; 
        
        map<string, int> mp; 
        
        for(auto it : words) {
            mp[it]++;
        }
        vector<pair<string, int>> vp; 
        for (auto it : mp) {
            vp.push_back(it); 
            // cout << it.first << ": " << it.second << endl; 
        }
        sort(vp.begin(),vp.end(), cmp);
        
        // for (auto it : vp) {
        //     cout << it.first << ": " << it.second << endl; 
        // }
        
        auto it = vp.begin();
        while (k--) {
            ans.push_back(it -> first);
            it++;
        }
        return ans; 
        
    }
};