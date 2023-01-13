//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    static bool cmp (pair<int, int> p1, pair<int, int> p2) 
    {
        return (p1.second < p2.second);
    }
    
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int, int>> vp; 
        
        for (int i = 0; i < n; i++) {
            vp.push_back({start[i], end[i]});
        }
        //sorted according to finish time
        sort(vp.begin(), vp.end(), cmp);
        // for (auto it : vp) {
        //     cout << it.first << ": " << it.second << endl; 
        // }
        int activity_count = 1; 
        int i = 0; //first activity is always selected
        for (int j = 1; j < n; j++) {
            
            if (vp[j].first > vp[i].second) {
               i = j; 
               activity_count++;  
            }
        }
        
        return activity_count; 
        
        
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends