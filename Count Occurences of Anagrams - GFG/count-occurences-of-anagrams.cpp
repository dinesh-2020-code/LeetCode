//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    int i = 0, j = 0 ; 
	    int k = pat.length(); 
	    int freq[26] = {0};             //Storing the freq of chars present in pat
	    for (int i = 0; i < k; i++) {
	        freq[pat[i] - 'a']++; 
	    }
	    int ans = 0; 
	    int freq1[26] = {0};          //for storing the freq chars in  particular window
	    while (j < txt.size()) {
	        
	        freq1[txt[j] - 'a']++;
	        if (j - i + 1 < k) {
	            j++; 
	        } 
	        else if ((j - i + 1) == k) {
	            bool flag = true; 
	           for (int i = 0; i < 26; i++) {
	               if (freq1[i] != freq[i]) {
	                   flag = false; 
	                   break; 
	               }
	           }
	           if (flag) 
	                ans++; 
	                
	            freq1[txt[i] - 'a']--;  //Removing the freq of ith char
	            i++; j++;               //Sliding the window
	        } 
	    }
	    return ans; 
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends