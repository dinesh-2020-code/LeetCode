/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* dfs(TreeNode *root, TreeNode* p, TreeNode *q) {
        if (root == NULL)
            return root; 
        
        if (root -> val > p -> val and root -> val > q -> val) {
            return dfs(root -> left, p, q); 
        }
        else if (root -> val < p -> val and root -> val < q -> val) {
            return dfs(root -> right, p, q); 
        }
        else {
            return root; 
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL; 
        
        return dfs(root, p, q); 
    }
};