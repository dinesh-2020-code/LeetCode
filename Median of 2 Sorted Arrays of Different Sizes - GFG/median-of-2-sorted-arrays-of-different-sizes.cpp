//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        if (array2.size() < array1.size()) 
            return MedianOfArrays(array2, array1); 
            
        int m = array1.size(), n = array2.size(); 
        if (n == 0) {           //array2 is empty
            int x = m / 2; 
            if (m % 2 == 0) {
                int a = array1[x]; 
                int b = array1[x + 1]; 
                return (a + b) / 2.0;
                 
            }
            else {
                 return array1[x];
            }
            
        }
        int low = 0, high = m; 
        
        while (low <= high) {
            int cut1 = (low + high) >> 1;
            int cut2 = (m + n + 1) / 2 - cut1; 
            
            int left1 = (cut1 == 0) ? INT_MIN : array1[cut1 - 1]; 
            int left2 = (cut2 == 0) ? INT_MIN : array2[cut2 - 1]; 
            
            int right1 = (cut1 == m) ? INT_MAX : array1[cut1]; 
            int right2 = (cut2 == n) ? INT_MAX : array2[cut2]; 
            
            if (left1 <= right2 && left2 <= right1) {
                if ((m + n) % 2 == 0) {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;   //median of even length array
                }
                else 
                    return (max(left1, left2));   //median of odd length of array
            }
            else if (left1 > right2) 
                high = cut1 - 1;           //move left
            else 
                low = cut1 + 1;            //move right
        }
        return 0.0; 
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends