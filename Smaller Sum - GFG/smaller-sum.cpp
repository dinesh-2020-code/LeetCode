//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        vector<pair<long long, long long>> vp; 
        for (int i = 0; i < n; i++) {
            vp.push_back({arr[i], i}); 
        }
        vector<long long> ans(n); 
        sort(vp.begin(), vp.end()); 
        long long int sum = 0; 
        ans[vp[0].second] = sum; 
        sum += vp[0].first; 
        for (long long int i = 1; i < n; i++)
        {
            auto curr = vp[i], prev = vp[i-1]; 
            if (curr.first == prev.first) {
                // ans.push_back(ans[i-1]); 
               
                ans[curr.second] = ans[prev.second];
            }
            else {
                // ans.push_back(sum); 
                ans[curr.second] = sum;
            }
            sum += curr.first; 
        } 
        return ans; 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends