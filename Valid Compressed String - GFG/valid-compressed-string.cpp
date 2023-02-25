//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool isAlphabet(char ch) {
        if (ch >= 'A' && ch <= 'Z')
            return true; 
        else 
            return false; 
    }
    int checkCompressed(string S, string T) {
        
        int ans = 0; 
        int j = 0, i = 0; 
        for (; i < T.length(); ) {
            // cout << S[i] << " " << T[j] << endl;; 
            if (isAlphabet(T[i]) && S[j] != T[i])
            {
                // cout << S[i] << " " << T[j] << endl;; 
                return ans; 
            }
            if (T[i] >= '0' && T[i] <= '9') {
                string num = ""; 
                
                while (T[i] >= '0' && T[i] <= '9') {
                    num += T[i++]; 
                }
                
                int nums = stoi(num);
                j += nums;
                
                // cout << nums << " "; 
                // i++; 
            }
            else {
                i++; j++; 
            }
        }
        if (i == T.length() && j == S.length())
            ans = 1; 
            
        // cout << j << endl;     
        return ans; 
        
        /*
            IXVGJREVJ
            3GJR4
            
            GOUAPUI
            GOUA0P1I
        */
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends