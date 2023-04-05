//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  private: 
    vector<int> factors(int N) {
        
        vector<int> fac; 
        fac.push_back(1); 
        for (int i = 2; i * i <= N; i++) {
            if (N % i == 0) {
                fac.push_back(i); 
                fac.push_back(N / i); 
            }
        }
        fac.push_back(N); 
        return fac; 
    }
    void print(vector<int> &v) {
        for (auto it : v) 
            cout << it << " "; 
            
        cout << endl; 
    }
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        
        int maxi = INT_MIN;
        unordered_map<int, int> mp; 
        for (int i = 0; i < N; i++) {
            mp[arr[i]]++; 
            maxi = max(maxi, arr[i]); 
        }
        
        int ans = 0; 
        for (int i = 0; i < N; i++) {
            vector<int> temp = factors(arr[i]); 
            // cout << "Factors of "<< arr[i] << " is : ", print(temp); 
            for (int j = 0; j < temp.size(); j++) {
                
                if (temp[j] != arr[i] && mp[temp[j]]) {
                    
                    ans++; 
                    break; 
                }
                else if (temp[j] == arr[i] && mp[temp[j]] > 1) {
                    // cout << "Hi\n"; 
                    ans++; break; 
                }
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
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends