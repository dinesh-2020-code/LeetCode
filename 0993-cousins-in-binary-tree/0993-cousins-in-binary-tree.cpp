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
    int level_x, level_y; 
    TreeNode *parent_x, *parent_y; 
    
    void dfs(TreeNode* root, int lvl, int x, int y, TreeNode * parent) {
        if (root == NULL)
        {
            return; 
        }
        if (root -> val == x) {
            level_x = lvl; 
            parent_x = parent; 
            return;
        }
        if (root -> val == y) {
            level_y = lvl; 
            parent_y = parent; 
            return; 
        }
        
        dfs(root -> left, lvl + 1, x, y, root); 
        dfs(root -> right, lvl + 1, x, y, root); 
        
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == nullptr)
            return false; 
        
        level_x = level_y = 0; 
        parent_x = parent_y = NULL; 
        
        dfs(root, 0, x, y, NULL); 
        
        return level_x == level_y && parent_x != parent_y; 
    }
};