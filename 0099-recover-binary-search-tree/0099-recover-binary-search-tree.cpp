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
    TreeNode *prev = NULL; 
    TreeNode *temp1 = NULL, *temp2 = NULL; 
    
    void inorder(TreeNode *root) {
        if (root == NULL)
            return; 
        
        inorder(root -> left); 
        if (prev != NULL && prev -> val > root -> val) {
            if (temp1 == NULL) {
                temp1 = prev; 
               
            }
            temp2 = root; 
        }
        prev = root; 
        inorder(root -> right); 
    }
public:
    void recoverTree(TreeNode* root) {
        if (root == NULL)
            return; 
        
        prev = NULL; 
        inorder(root); 
        int temp = temp1 -> val; 
        temp1 -> val = temp2 -> val;
        temp2 -> val = temp; 
        
    }
};