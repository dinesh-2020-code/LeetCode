//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	    long long int ans = 1;  // 1 chick initially
	    
	    vector<long long int> dp(n); 
	    dp[0] = 1; 
	    
	    for (int i = 1; i < n; i++) {
	        if (i - 6 >= 0) {
	            ans -= dp[i - 6]; 
	            
	        }
	        dp[i] = 2 * ans; 
	        
	        ans += dp[i]; 
	    }
	    return ans;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends