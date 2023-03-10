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
    	ll maxi = -1, secondMax = -1, thirdMax = -1; 
    	ll mini = -1, secondMin = -1; 
    	
    	for (int i = 0; i < n; i++) {
    	    if (maxi == -1) {
    	        maxi = i; 
    	    }
    	    else {
    	        if (arr[i] > arr[maxi])
    	            maxi = i; 
    	    }
    	}
    	
    	for (int i = 0; i < n; i++ ) {
    	    if (i != maxi && secondMax == -1) {
    	        secondMax = i; 
    	    }
    	    else if (i != maxi && arr[i] > arr[secondMax]) {
    	        secondMax = i; 
    	    }
    	    
    	}
    	
    	//thirdMax
    	for (int i = 0; i < n; i++) {
    	    if (i != maxi && i != secondMax && thirdMax == -1) 
    	        thirdMax = i; 
    	    else if (i != maxi && i != secondMax && arr[i] > arr[thirdMax])
    	        thirdMax = i; 
    	}
    	
    // 	cout << maxi << " " << secondMax << " " << thirdMax << endl; 
    	
    	//mini 
    	for (int i = 0; i < n; i++) {
    	    if (mini == -1) 
    	        mini = i; 
    	   else if (arr[i] < arr[mini])
    	        mini = i; 
    	}
    	//secondMin
    	for (int i = 0 ; i < n; i++) {
    	    if (i != mini) {
    	        if (secondMin == -1)
    	            secondMin = i; 
    	       else if (arr[i] < arr[secondMin])
    	            secondMin = i ;
    	    }
    	}
    	
    	ll p1 = arr[maxi] * arr[mini] * arr[secondMin]; 
    	ll p2 = arr[maxi] * arr[secondMax] * arr[thirdMax]; 
    	
    	return max(p1, p2); 
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