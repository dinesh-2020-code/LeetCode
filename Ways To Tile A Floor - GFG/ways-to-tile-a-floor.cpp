//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long mod = 1e9+7;
    long long solve(long long n, long long dp[]) {
        if (n == 0) 
            return dp[n] = 1; 
        if (n == 1) 
            return dp[n] = 1;
        
        if (dp[n] != -1) 
            return dp[n] % mod; 
            
        return dp[n] = (solve(n-1, dp) + solve(n-2, dp)) % mod;     
    }
    long long numberOfWays(long long N) {
        
        long long dp[N+1]; 
        memset(dp, -1, sizeof(dp)); 
        return solve(N, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.numberOfWays(N) << endl;
    }
    return 0;
}
// } Driver Code Ends