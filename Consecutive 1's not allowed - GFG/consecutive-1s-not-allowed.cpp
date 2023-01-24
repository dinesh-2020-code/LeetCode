//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	
	ll noOfWays(int dp[], int n) {
	    if (n == 0)
	        return (dp[n] = 1); 
	   if (n == 1)
	        return (dp[n] = 2); 
	        
	   if (dp[n] != -1)
	        return dp[n] % 1000000007;
	    
	    return dp[n] = (((noOfWays(dp , n - 1)) % 1000000007) + ((noOfWays(dp , n - 2)) % 1000000007)) % 1000000007;
	}
	ll countStrings(int n) {
	    
	    int dp[n + 1] ; 
	    memset(dp, -1, sizeof(dp)); 
	    return noOfWays(dp, n); 
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends