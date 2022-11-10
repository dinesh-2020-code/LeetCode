class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "" ; 
        
        stack<int> st; 
        
        for (int i = 0; i < s.length(); i++) {
            
            if (st.empty()) {
                st.push(s[i]);
            }
            else {
                if (st.top() == s[i])
                while (st.empty() == false && st.top() == s[i]) {
                    st.pop();
                }
                
                else 
                    st.push(s[i]);
            }
        }
        
        while (!st.empty())
        {
            ans += st.top(); 
            st.pop();
        }
        
        reverse(ans.begin(), ans.end() ); 
        return ans; 
    }
};