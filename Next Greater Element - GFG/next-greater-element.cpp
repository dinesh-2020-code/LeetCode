//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        vector<long long> ans;
        stack<long long> stk; 
        
        ans.push_back(-1);
        stk.push(arr[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            
            while (!stk.empty() && stk.top() <= arr[i])
            {
                stk.pop();
            }
            
            (stk.size() > 0 ) ? ans.push_back(stk.top()) : ans.push_back(-1);
            stk.push(arr[i]);
        }
        reverse(ans.begin(), ans.end()); 
        return ans; 
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends