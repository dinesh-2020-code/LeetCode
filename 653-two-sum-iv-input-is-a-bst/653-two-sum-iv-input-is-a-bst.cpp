/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //search a given node in BST
    bool search(TreeNode *root, int item, TreeNode *check) {
        if (root == nullptr)
            return false; 
        if (item == root -> val && root != check)
            return true; 
        else if (item < root -> val) 
            return search(root -> left, item, check);
        else 
            return search(root -> right, item, check); 
        
    }
    bool inorder(TreeNode* root, int k, TreeNode *temp) {
        
        if (root == nullptr)
            return false; 
        
        bool l =  inorder(root -> left, k, temp); 
        
        if (search(temp, (k - root -> val), root)) {
            return true; 
        }
        bool r=  inorder(root -> right, k, temp); 
        return l or r;
        
    }
    bool findTarget(TreeNode* root, int k) {
        
        TreeNode *temp = root; 
        
        return inorder(root, k, temp); 
        
    }
    
    /*
    //inorder traversal
    void solve(TreeNode* root, int k, vector<int> &t) {
        if (root == nullptr)
            return; 
        solve(root -> left, k, t);
        t.push_back(root -> val); 
        solve(root -> right, k, t); 
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v ;
        solve(root, k, v); 
//         for (auto i : v)
//             cout << i << " "; 
        
        int i = 0, j = v.size() - 1; 
        
        while (i < j) {
            if (v[i] + v[j] == k)
                return true; 
            else if (v[i] + v[j] > k)
                j--; 
            else 
                i++; 
        }
        
        return false; 
        
    }
    */
};