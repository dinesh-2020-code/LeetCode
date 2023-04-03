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
    
private: 
    int answer = 0; 
    //O(n) time
    //O(h) aux space
    int dfs(TreeNode *root, int currVal) {
        if (root == nullptr)
            return 0;
        
       
        if (root -> left == nullptr && root -> right == nullptr) 
        {
            return (currVal * 10 + root -> val); 
            
        }
        int case1 = dfs(root -> left, (currVal * 10 + root -> val));
        
        int case2 = dfs(root -> right, (currVal * 10 + root -> val));
        
        return (case1 + case2); 
    }
public: 
    int sumNumbers(TreeNode* root) {
        
        return dfs(root, 0);
        
    }
};