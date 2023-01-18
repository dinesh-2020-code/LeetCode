//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int> span; 
        span.push_back(1);
        
        stack<int> st;  // st will store indexes 
        st.push(0); 
        
        for (int i = 1; i < n; i++) {
            
            while (!st.empty() && price[st.top()] <= price[i]) {
                st.pop(); 
            }
            
            (st.empty()) ? span.push_back(i+1) : span.push_back(i - st.top()); 
            st.push(i);
            
        }
        return span; 
        
        
        /*
            42
            68 735 101 770 525 279 559 563 465 106 146 82 28 362 492 596 743 28 637 392 205 703 154 293 383 622 317 519 696 648 127 372 339 270 713 68 700 236 295 704 612 123
        
        */
        
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends