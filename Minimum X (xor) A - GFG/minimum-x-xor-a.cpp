//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSetBits(int n) {
        int ans = 0; 
        while (n > 0) {
            if (n & 1) {
                ans++; 
            }
            n = n >> 1;
        }
        return ans; 
    }
    int minVal(int a, int b) {
        int s1 = countSetBits(a); 
        int s2 = countSetBits(b); 
        // cout << s1 << " " << s2 <<endl; 
        int ans = a; 
        if (s1 == s2) {
            ans = a; 
        }
        
        else if (s1 < s2) {   //increment the set bits from right to left to make s1 = s2
            
            int idx = 0; 
            while (s1 != s2) {
                if (!(a & 1) ) {
                    s1++;
                    ans += (1 << idx);
                }
                idx++; 
                a = a/2;
                
            }
        }
        else {    //decrement the set bits from right to left to make s1 = s2 
            int idx = 0;
            while (s1 != s2) {
                if (a & 1 == 1) {
                    s1--; 
                    ans -= (1 << idx);
                }
                idx++; 
                a = a / 2; 
            }
        }
        return ans; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends