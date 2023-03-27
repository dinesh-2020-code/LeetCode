//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int ways(int N, int K, int pre, vector<vector<vector<int>>> &dp) {
        
        if (N == 0 && K == 0) {
            return 1; 
        }
        if (dp[pre][N][K] != -1)
            return dp[pre][N][K]; 
        if (K == 0)
            return 0; 
        if (pre > N)
            return 0;     
         
        int cnt = 0;
        for (int i = pre; i <= N; i++) {
            cnt += ways(N-i, K-1, i, dp); 
        }
        return dp[pre][N][K] = cnt; 
        
        //
        //7 3 1
        //6 2 1
        // 5 1 1
        // 4 0 1
    }
    
    int countWaystoDivide(int N, int K) {
        // Code hereint
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(N+1, vector<int> (K+1,-1)));
        
        //vector<vector<vector<data_type>>> vector_name(x, vector<vector<data_type>>(y, vector<data_type>(z,value)));
        //dp[pre][N][K];
        return ways(N, K, 1,dp);
        
        /*
            [1, 1, 1, 5]
            [1, 1, 2, 4]
            [1, 1, 3, 3]
            [1, 2, 2, 3]
            [2, 2, 2, 2]
            
        */
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends