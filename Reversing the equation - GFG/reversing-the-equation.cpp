//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
    {
        stack<string> st; 
        string no = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '+' or s[i] == '-' | s[i] == '*' or s[i] == '/'){
                st.push(no);
                no = "";
                string temp(1, s[i]);   //converting 'char' to 'string'
                st.push(temp); 
            }
            else {
                no += s[i]; 
                
                
            }
        }
        st.push(no);
        string ans = "";
        while (!st.empty()) {
           
            ans += st.top(); 
            st.pop(); 
        }
        
        return ans; 
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends