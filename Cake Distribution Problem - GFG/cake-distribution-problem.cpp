//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
private: 
    bool isPossible(int ans, int N, int K, vector<int> &sweetness) {
        
        int sweet = 0;
        int count = 0; 
        
        for (int i = 0; i < N; i++) {
            
            if ((sweet + sweetness[i]) >= ans) {
                count++; 
                sweet = 0; 
            }
            else {
                sweet += sweetness[i];
            }
            
        }
        if (sweet >= ans) 
            count++; 
        
        return (count >= (K + 1));
    }
    
public:
    int maxSweetness(vector<int>& sweetness, int N, int K) {
        int sum = 0; 
        for (auto i : sweetness) 
            sum += i; 
            
        int low = 0, high = sum + 1;
        
        while (high - low > 1) {
            int mid = low + (high - low) / 2; 
            
            if (isPossible(mid, N, K, sweetness)) {
                low = mid; 
            }
            else {
                high = mid; 
            }
        }
        return low; 
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends