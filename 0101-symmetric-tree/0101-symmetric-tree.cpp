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
    bool isValid; 
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true; 
        
        isValid = true; 
        dfs(root -> left, root -> right); 
        return isValid; 
        
    }
    void dfs(TreeNode *left, TreeNode *right) {
        //base case
        if (left == NULL && right == NULL)
            return; 
        
        if (left == NULL || right == NULL)
        {
            isValid = false; 
            return ; 
        }
        if (left -> val != right -> val)
        {
            isValid = false; 
            return; 
        }
        
        dfs(left -> left, right -> right); 
        dfs(left -> right, right -> left); 
        
    }
    
};