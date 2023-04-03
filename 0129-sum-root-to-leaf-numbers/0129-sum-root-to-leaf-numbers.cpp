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
    void dfs(TreeNode *root, int currVal) {
        if (root == nullptr)
            return ;
        
        dfs(root -> left, (currVal * 10 + root -> val));
        if (root -> left == nullptr && root -> right == nullptr) 
        {
            answer += (currVal * 10 + root -> val); 
            return ;
        }
        
        
        dfs(root -> right, (currVal * 10 + root -> val));
    }
public: 
    int sumNumbers(TreeNode* root) {
        
        dfs(root, 0);
        return answer; 
    }
};