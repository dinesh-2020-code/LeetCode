//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

#define ll long long
class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	sort(arr, arr + n);
    	ll p1 = arr[0] * arr[1] * arr[n-1];
    	ll p2 = arr[0] * arr[n-1] * arr[n-2] 
    	; 
    	ll p3 = arr[n-1] * arr[n-3] * arr[n-2]; 
    	
    	return max(p1, max(p2, p3)); 
    	
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends