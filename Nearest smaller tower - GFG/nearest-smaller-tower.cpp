//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
private: 
    void print(vector<int> &v) {
        for (auto it : v) 
            cout << it << " "; 
        cout << endl; 
    }
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        int n = arr.size(); 
        vector<int> ans(n), leftMin(n), rightMin(n);
        stack<int> st; 
        // calculating the leftMin for every element
        
        st.push(0);
        leftMin[0] = -1; //for leftmost element there is nothing to the left so minimum index will be -1
        for (int i = 1; i < n; i++) {
            
            while (!st.empty() && arr[st.top()] >= arr[i]) 
                st.pop(); 
                
            (st.empty()) ? (leftMin[i] = -1) : (leftMin[i] = st.top()); 
            st.push(i);
        } 
        
        //calculating the rightMin array
        st = stack<int>(); //emptying the stack by assigning a new stack
        
        rightMin[n-1] = -1; 
        st.push(n-1);
        
        for (int i = n - 2; i >= 0; i--) {
            
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop(); 
            }
            (st.empty()) ? rightMin[i] = -1 : rightMin[i] = st.top();  
            st.push(i);
        }
        // print(leftMin);
        // print(rightMin);
        for (int i = 0; i < n; i++) {
            if (leftMin[i] != -1 && rightMin[i] != -1) {
                int leftDist = i - leftMin[i];
                int rightDist = rightMin[i] - i; 
                
                if (leftDist < rightDist){  //equal and smaller 
                    ans[i] = leftMin[i];
                }
                else if (leftDist > rightDist) {
                    ans[i] = rightMin[i]; 
                }
                else { //equal part
                    if (arr[leftMin[i]] == arr[rightMin[i]]) {
                        ans[i] = leftMin[i]; 
                    }
                    else {
                        int minHeight = min(arr[leftMin[i]], arr[rightMin[i]]); 
                        if (minHeight == arr[leftMin[i]])
                            ans[i] = leftMin[i]; 
                        else 
                            ans[i] = rightMin[i]; 
                    }
                }
               
            }
            else if (leftMin[i] == -1 && rightMin[i] == -1) {
                ans[i] = -1; 
            }
            else { //either of them is -1
                if (leftMin[i] == -1) {
                    ans[i] = rightMin[i]; 
                }
                else {
                    ans[i] = leftMin[i]; 
                }
            }
        }
        
    //   8
    //   7 3 4 1 5 10 1 1
        return ans; 
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends