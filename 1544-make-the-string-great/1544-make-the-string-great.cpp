class Solution {
public:
    string makeGood(string s) {
        string ans = ""; 
        if (s == "")
            return ans;
        
        int i = 0; 
        stack<int> st; 
        
        for( i = 0; i < s.length(); i++) {
            
            if (st.empty()) {
                st.push(s[i]); 
                
            }
            else {
                if (abs (s[i] - st.top()) == 32) {
                    st.pop(); 
                }   
                else 
                {
                    st.push(s[i]); 
                }
            }
        } 
        
        while (!st.empty()) {
            ans += st.top(); 
            st.pop();
        }
        reverse(ans.begin(), ans.end()); 
        
        return  ans;
    }
};