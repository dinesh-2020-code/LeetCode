//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        int mp[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            mp[s[i] - 'a']++; 
        }
        
        int b = mp['b' - 'a'], a = mp['a' - 'a'], l = mp['l' - 'a'] / 2, o = mp['o' - 'a'] / 2, n = mp['n' - 'a'];
        return (min(b,min(a, min(l, min(o, n)))));
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends