//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        int start = 1, end = 2000, mid = 0; 
        int temp = (R * C) / 2; 
        int c = 0, result = 0; 
        while (start <= end) {
            c = 0;
            mid = start + (end - start) / 2; 
            for (int i = 0; i < R; i++) {
                c += lower_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin(); 
            }
            
            if (c <= temp) {
                result = mid;
                start = mid + 1; 
            }
            else {
                end = mid - 1; 
            }
            
        }
        
        return result;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends