class Solution {
public:
    void clear(vector<int> &mp){
        for(auto &it : mp)it = 0;
    }
    int partitionString(string s) {
        vector<int> mp(26,0);
        int cnt = 0;
        for(int i = 0; i< s.length(); i++){
            mp[s[i]-'a']++;
            if(mp[s[i]-'a']>1){
                cnt++;
                clear(mp);
                mp[s[i]-'a']++;
            }
        }
        return cnt+1;
    }
};