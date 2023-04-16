//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    long long solve(int N, vector<int> &A, vector<int> &B) {
        vector<int>o1, e1, o2, e2;
        for(int i = 0; i<N; i++){
            if(A[i]%2)o1.push_back(A[i]);
            else e1.push_back(A[i]);
            
            if(B[i]%2)o2.push_back(B[i]);
            else e2.push_back(B[i]);
        }
        if(o1.size()!=o2.size() || e1.size()!= e2.size())return -1;
        int inc = 0, dec = 0;
        sort(o1.begin(), o1.end());
        sort(o2.begin(), o2.end());
        sort(e1.begin(), e1.end());
        sort(e2.begin(), e2.end());
        for(int i = 0; i<o1.size(); i++){
            if(o1[i] < o2[i]){
                inc += (o2[i]-o1[i])/2;
            }
            else{
                dec += (o1[i]-o2[i])/2;
            }
        }
        
         for(int i = 0; i<e1.size(); i++){
            if(e1[i] < e2[i]){
                inc += (e2[i]-e1[i])/2;
            }
            else{
                dec += (e1[i]-e2[i])/2;
            }
        }
        return (inc == dec) ? inc : -1;
        
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends