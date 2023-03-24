//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
private: 
    Node *targetAddr = NULL; 
    int getSumFromRootToTarget(Node *root, int target, int &sum) {
        if (root == NULL)
            return -1; 
        if (root -> left == NULL && root -> right == NULL) {  // Is node is a leaf?
            if (root -> data == target) {
                targetAddr = root; 
                return sum; 
            }
            else 
                return -1;
        }
        
        else if (root -> data == target) {
            targetAddr = root; 
            return sum; 
        }
        else if (root -> data < target) {
            sum += root -> data; 
            return getSumFromRootToTarget(root -> right, target, sum); 
        }
        else {
            sum += root -> data; 
            return getSumFromRootToTarget(root -> left, target, sum); 
        }
        
    }
    
    int getSumFromTargetToLeaf(Node *ptr) {
        
        if (ptr == NULL) {
            return -1; 
        }
        if ((ptr -> left == NULL && ptr -> right == NULL)) { //leaf node
            return (ptr -> data); 
        }
        
        int lSum = getSumFromTargetToLeaf(ptr -> left); 
        
        int rSum = getSumFromTargetToLeaf(ptr -> right); 
        
        if (lSum != -1 && rSum != -1) {
            return (ptr -> data) + min(lSum, rSum); 
        }
        else if (lSum == -1) {
            return (ptr -> data) + rSum;    
        }
        else {
            return (ptr -> data) + lSum; 
        }
        
    }
public:
    int maxDifferenceBST(Node *root,int target){
        
        int sum1 = 0;  // sum till target from root
        
        sum1 = getSumFromRootToTarget(root, target, sum1); 
        if (targetAddr == NULL) {
            return -1; 
            cout << targetAddr -> data << endl; 
        }
        // cout << "Sum1 = " << sum1 << endl; 
        
        int sum2 = getSumFromTargetToLeaf(targetAddr) - (targetAddr -> data);
        // cout << "Sum2 = " << (sum2 - targetAddr -> data) << endl; 
        return (sum1 - sum2); 
        
    }
    
    /*
        7
        18 7 13 4 8 1 11
        6
    */
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends