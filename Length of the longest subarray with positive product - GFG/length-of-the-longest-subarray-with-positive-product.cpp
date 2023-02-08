//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           
           int ans = 0; 
           
           for (int i = 0; i < n; ) {
               int start = i, end ;
               
               while (start < n && arr[start] == 0) 
                    start++; 
                    
                    
                end = start ; 
                int count = 0;  //count of negative numbers
                int startneg = -1, endneg = -1;
                
                while (end < n && arr[end] != 0) {
                    if (arr[end] < 0) {
                        count++; 
                        if (startneg == -1) {
                            startneg = end; 
                        }
                        endneg = end; 
                    }
                    end++; 
                }
                
                if (count % 2 == 0) { //neg numbers count is even
                    ans = max(ans, end - start);
                }
                else {
                    if (startneg != -1) {
                        ans = max(ans, end - startneg - 1); 
                    }
                    if (endneg != -1) {
                        ans = max(ans, endneg - start);
                    }
                }
                i = end + 1; 
                
                
           }
            return ans; 
            
            
            //Time Complexity: O(N) as every element is traversed only once 
            //Space Complexity: O(1)
          
           
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends