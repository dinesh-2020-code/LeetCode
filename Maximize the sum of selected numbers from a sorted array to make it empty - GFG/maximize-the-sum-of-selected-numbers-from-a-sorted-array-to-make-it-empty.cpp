//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        map<int, int, greater<int>> mp; 
        
        for (int i = 0; i < n; i++)
        {
            mp[a[i]]++; 
        }
        
        // for (auto it : mp) {
        //     cout << it.first << " : " << it.second << endl ;
        // }
        int ans = 0; 
        for (auto it : mp) {
            
            while (mp[it.first] > 0) {
                //cout << ans << " "; 
                ans += it.first; 
                mp[it.first]--; 
                if (mp[it.first-1] > 0)
                    mp[it.first - 1]--; 
            }
            // cout << ans << " "; 
        }
        
        // cout << endl; 
        
        
        return ans; 
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends