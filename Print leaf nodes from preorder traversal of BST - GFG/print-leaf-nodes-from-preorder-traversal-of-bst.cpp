//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leafNodes(int arr[],int N) {
        
        vector<int> ans; 
        
        stack<int> st; 
        
        for (int i = 0, j = 1; i < N && j < N;  ) {
            
            if (arr[i] > arr[j]) {
                st.push(arr[i]); 
            }
            else {
                int temp = arr[i]; 
                
                bool flag = false; 
                
                while (!st.empty() and st.top() < arr[j]) {
                   
                        st.pop();
                        flag = true;
                    
                    
                }
                
                if (flag) {
                    ans.push_back(arr[i]); 
                }
            }
            i++; j++;
            
        }
        ans.push_back(arr[N-1]);
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
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends