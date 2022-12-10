//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    string ans = "";
    
    stack<char> st;
    
    for (int i = 0; i < num.length(); i++) {
        
        while (!st.empty() && st.top() > num[i] && k--> 0 )  // order of conditions matter here !
            st.pop();
            
        st.push(num[i]);
    }
    
    while (k--> 0){
        st.pop(); 
    }
    
    while (!st.empty()) {
        ans += st.top(); 
        st.pop(); 
    }
    
    while (ans.back() == '0')
        ans.pop_back(); 
        
    reverse(ans.begin(), ans.end());
        
    return (ans.empty()) ? "0" : ans; 
}