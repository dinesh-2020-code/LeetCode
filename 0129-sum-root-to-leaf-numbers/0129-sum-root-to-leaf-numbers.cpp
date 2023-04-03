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
    void dfs(TreeNode * root, int currVal) {
        if (root == nullptr)
            return ;
        
        if (root -> left == nullptr && root -> right == nullptr ) {
            answer += (currVal); 
            return ; 
        }
        if (root -> left != NULL)
            dfs(root -> left, currVal * 10 + root -> left -> val); 
        if (root -> right != NULL)
            dfs(root -> right, currVal * 10 + root -> right -> val); 
    }
public:
    int sumNumbers(TreeNode* root) {
        
        dfs(root, root -> val); 
        return answer; 
        
    }
};