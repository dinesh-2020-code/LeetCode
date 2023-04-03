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
    int answer = 0; 
public:
    
    void dfs(TreeNode *root, int currVal) {
        if (root == nullptr)
            return ;
    
        if (root -> left == nullptr && root -> right == nullptr) 
        {
            answer += (currVal * 10 + root -> val); 
            return ;
        }
        
        dfs(root -> left, (currVal * 10 + root -> val));
        dfs(root -> right, (currVal * 10 + root -> val));
    }
    int sumNumbers(TreeNode* root) {
        
        dfs(root, 0);
        return answer; 
    }
};