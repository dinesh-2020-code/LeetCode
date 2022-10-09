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
};