//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    vector<int> freq(26,0);
		    int max_freq=0;
		    int start=0,end=0;
		    int ans=0;
		    while(end<s.length())
		    {
		        int curr = freq[s[end++]-'A']++;// Add new element to the window
		        
		        max_freq = max(max_freq,curr+1); // find the max freq
		        
		        if((k+max_freq)<(end-start)) // if not possibel to make all char same reduce the window
		            freq[s[start++]-'A']--; // by decreasing the freq of start char and increasing the start pointer
		        else
		        ans = max(end-start,ans); // if possible update the answer
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends