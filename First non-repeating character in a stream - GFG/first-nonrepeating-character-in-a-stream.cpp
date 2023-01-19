//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    string ans; 
		    int n = A.size(); 
		    int freq[26] = {0};
		    queue<char> q; 
		    int i = 0; 
		    while(i < n) {
		        int val = A[i] - 'a'; 
		        freq[val]++; 
		        q.push(A[i]);
		        while (!q.empty() && freq[q.front() - 'a'] > 1) {
		            q.pop();
		            
		        }
		        if (q.empty()) 
		            ans.push_back('#');
		            
		        else {
		            ans.push_back(q.front());
		        } 
		        i++;
		            
		         
		    }
		  //  cout << n << endl; 
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends