//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        
        stack<char> st ; 
        string ans = "";
        
        for (int i = 0; i < s.size(); i++) {
            //if closing bracket encountered
            if (s[i] == ']') 
            {
                //concatenate to the string 'ans' until opening brace encounters
                while (st.empty() == false && st.top() != '[') 
                {
                    ans = st.top() + ans; 
                    st.pop(); 
                }
                if (st.empty() == false)
                    st.pop(); 
                
                //extracting the number
                
                string number = ""; 
                while (!st.empty() && st.top() >= '0' && st.top() <= '9') {
                    number = st.top() + number; 
                    st.pop(); 
                }
                
                int digit_n = stoi(number); 
                
                //concatenating ans to ans digit_n - 1 times
                
                string temp = ans; 
                
                for (int i = 0; i < digit_n - 1; i++) {
                    ans += temp; 
                }
                
                //pushing the 'ans' again to stack
                
                for (int i = 0; i < ans.size(); i++)
                    st.push(ans[i]);
                    
                ans = "";
            }
            else {
                st.push(s[i]);
            }
        }
        
            while (!st.empty()) {
                ans = st.top() + ans;
                st.pop();
            }
            return ans; 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends