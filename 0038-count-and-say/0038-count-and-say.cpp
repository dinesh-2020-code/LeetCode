class Solution {
public:
    //pairing the freq and count of char into the vector of pairs
    void say(string str,vector<pair<int, char>> &vp) 
    {
        int n = str.size(); 
        int i = 0, j = 0; 
        for (i = 0; i < n; ) {
            int key = 0 , value = str[i]; 
            j = i;
            int cnt = 0; 
            for (; j < n; j++) {
                if (str[j] != str[i]) {
                    break; 
                }
                else 
                    cnt++; 
                
            }
            vp.push_back({cnt, value});
            i = j; 
        }
        
        
    }
    
    string concatenate (vector<pair<int, char>> vp) {
        string res = "";
        string temp = "";
        for (auto it : vp)
        {
            temp = to_string(it.first) + it.second; 
            res += temp; 
        }
        
        return res; 
    }
    string countAndSay(int n) {
        string ans = ""; 
        
        ans = "1"; 
        
        int i = 1; 
        map<int, int>mp;
        vector<pair<int, char>> vp; 
        
        
        while (i < n) 
        {
            say (ans, vp); 
            ans = concatenate(vp); 
            
            i++;
            
            vp.clear(); 
            
        }
        
        return ans; 
    }
};