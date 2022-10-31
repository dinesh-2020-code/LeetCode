//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int A[], int N) {
        vector<int> ans; 
        unordered_map<int, vector<int>> mp; 
        
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                
                int sum = A[i] + A[j]; 
                if (mp.find(sum) != mp.end() and mp[sum][0] != i and mp[sum][1] != j and mp[sum][0] != j and mp[sum][1] != i) {
                    vector<int> temp = {mp[sum][0], mp[sum][1], i, j};
                    if (ans.empty() or temp < ans)
                    {
                        ans = temp; 
                    }
                    
                }
                else {
                    mp[sum].push_back(i);
                    mp[sum].push_back(j);
                }
            }
        }
        
        if (ans.size() == 0) 
            return {-1, -1, -1, -1};
            
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends