//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        vector<long long int> ans; 
        
        long long int Xor = 0, res1 = 0, res2 = 0, rightmostSetBit = 0; 
        for (long long int i = 0; i < N; i++) 
            Xor ^= Arr[i]; 
            
        //now xor will contain the XOR of two odd appearing numbers
        //we will find the rightmost set bit in the xor and divide the Arr into two groups 
        //(one group contains the rightmost set bit as 0 , while other group contains the rightmoost set bit as 1)
        
        rightmostSetBit = Xor & ~(Xor - 1);
        
        for (long long int i = 0; i < N; i++) {
            if (Arr[i] & rightmostSetBit) 
                res1 ^= Arr[i]; 
                
            else 
                res2 ^= Arr[i]; 
        }
        
        if (res1 > res2) {
            ans.push_back(res1); 
            ans.push_back(res2); 
        }else {
            ans.push_back(res2); 
            ans.push_back(res1); 
        }
        
        return ans; 
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends