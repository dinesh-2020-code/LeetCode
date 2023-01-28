//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    const int mod = 1000000007;
	    int fn(int ind, string &str, int dp[]){
            if(ind == str.length())
                return dp[ind] = 1;
            
            // try all the possible ways:
            
            if (dp[ind] != -1)
                return dp[ind]; 
                
            int ans1 = 0, ans2 = 0; 
            
            if ((ind + 1) <= str.length()) {
                int n = str[ind] - '0';
                if (n != 0) {
                    ans1 = fn(ind + 1, str, dp);
                }
                
            }
            
            if (ind + 2 <= str.length()) {
                string temp = str.substr(ind, 2); 
                int n = stoi(temp);
                if (n >= 10 && n <= 26) {
                    ans2 = fn(ind + 2, str, dp); 
                }
            }
            return dp[ind] = (ans1 + ans2) % mod; 
            
            
            
            
	    }
		int CountWays(string str){
		    
		    int dp[str.length() + 1];
		    memset(dp, -1, sizeof(dp)); 
		    return fn(0, str,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends