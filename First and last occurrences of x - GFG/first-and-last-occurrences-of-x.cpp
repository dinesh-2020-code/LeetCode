//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


int first_occ(int arr[], int n, int  x) {
    int ans = -1 ;
    
    int start = 0, end = n - 1, mid; 
    
    while (start <= end) 
    {
        mid = start + (end - start) / 2; 
        
        if (arr[mid] == x) {
            ans = mid; 
            end = mid - 1;
        }
        else if (arr[mid] > x ) {
            
            end = mid - 1; 
        }
        else    // arr[mid] < x; 
            start = mid + 1; 
        
    }
    return ans; 
}

int last_occ(int arr[], int n, int  x) {
    
    int start = 0, end = n - 1, mid = 0;
    int ans = -1;
    
    while (start <= end) 
    {
        mid = start + (end - start) / 2; 
        
        if (arr[mid] == x) {
            ans = mid; 
            start = mid + 1; 
        }
        else if (arr[mid] < x) {
            
            start = mid + 1; 
        } 
        
        else {           //arr[mid] >= x
            
            end = mid - 1; 
        }
            
        
    }
    
    return ans; 
}
vector<int> find(int arr[], int n , int x )
{
    
    vector<int> ans(2) ;
    
    ans[0] = first_occ(arr, n, x); 
    ans[1] = last_occ(arr, n, x); 
    
    return ans; 
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends