class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st; 
        
        int i = 0, j = 0; 
        int n = pushed.size(); 
        
        while (i < n) {
            if (pushed[i] != popped[j]) {
                while (!st.empty() && st.top() == popped[j]) {
                    st.pop(); 
                    j++;
                }
                st.push(pushed[i]); 
                i++; 
            }
            else {
                j++; i++;
            }
            
        }
        while (!st.empty()) {
            
            if (st.top() != popped[j]) {
                return false;

            }
            st.pop(); 
            j++;
        }
        return true; 
    }
};