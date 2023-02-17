//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        
        int i = 0, j = 1; 
        
        if (N <= K) {
            return GeekNum[N-1]; 
        }
        long long int sum = 0; 
        for (int i = 0; i < K; i++) {
            sum += GeekNum[i]; 
        }
        long long int a = GeekNum[i], b = GeekNum[j];
        
        for (int k = K; k < N; k++) {
            
            int temp = a; 
            GeekNum.push_back(sum);
             
            i++;
            sum += GeekNum.back(); 
            sum -= a; 
            a = GeekNum[i]; 
            
        }
        
        return GeekNum[N-1]; 
        
        // k = 3
        // 0 1 2 3 6 11 20 37 68 125
        // 1 2 3 4 5 6  7  8  9  10 
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends