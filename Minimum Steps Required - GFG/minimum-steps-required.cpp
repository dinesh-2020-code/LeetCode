//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    
    int aGroups = 0, bGroups = 0; 
    
    
    for (int i = 0; i < str.length(); ) {
        if (str[i] == 'a') {
            aGroups++; 
            
            while (i < str.size() && str[i] == 'a') {
                i++;
            }
        }
        else {
            bGroups++; 
        
            while (i < str.size() && str[i] == 'b') {
                i++; 
            }
        }
    }
    
    int ans = min(aGroups, bGroups) + 1; 
    return ans; 
    
    
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends