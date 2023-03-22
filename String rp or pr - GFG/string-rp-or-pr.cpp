//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int X,int Y,string S){
        long long ans = 0; 
          
        stack<int> st; 
        st.push(S[0]); 
          
          // "pr" -> X 
          // "rp" -> Y
        for (int i = 1; i < S.size(); i++) {
            
            if (S[i] == 'r' && X >= Y) { //pr case
                if(st.size() && st.top() == 'p') {
                    st.pop(); 
                    ans += X; 
                }
                else {
                    st.push(S[i]); 
                }
            }
            else if (S[i] == 'p' && Y >= X) {
                if (st.size() && st.top() == 'r') {
                    st.pop(); 
                    ans += Y; 
                }
                else {
                    st.push(S[i]); 
                }
            }
            else {
                st.push(S[i]);
            }
        }
        
        //removing remaining pr , rp
        
        stack<char> st2; 
        
        while (st.size() && X != Y) {
            if (st.top() == 'r' && st2.size() && st2.top() == 'p') {
                ans += Y; 
                st2.pop(); 
            }
            else if (st.top() == 'p' && st2.size() && st2.top() == 'r') {
                ans += X; 
                st2.pop(); 
            }
            else {
                st2.push(st.top()); 
            }
            
            st.pop(); 
        }
        
        return ans;
          
      // 6 8
      // "rprrprri"
    //   10 20
    //   lrrfrrprgprpppppmurr  op; 40
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends