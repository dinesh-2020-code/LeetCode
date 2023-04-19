//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        
        vector<int> mark(N, 0); 
      
        for (int i = 0; i < N; ) {
            
            if (S[i] == '1') {
                mark[i] = 1; 
                int temp = X; 
                int j = i - 1, k = i + 1; 
                while (j >= 0 && temp--) {
                    mark[j--] = 1; 
                    
                }
                
                temp = X; 
                while  (k < N && temp-- ) {
                    mark[k++] = 1; 
                }
                i++;
            }
            else {
                i++; 
            }
            
        }
        
        for(int i = 0; i < mark.size(); i++) {
            if (mark[i] == 0)
                return false; 
        }
        return true; 
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends