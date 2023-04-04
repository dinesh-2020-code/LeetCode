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
    
    
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == nullptr)
            return false; 
        
        queue<TreeNode*> q; 
        
        q.push(root); 
        while (!q.empty()) {
            int size = q.size(); 
            
            bool xFound = false, yFound = false; 
            
            for (int i = 0; i < size; i++) {
                TreeNode * curr = q.front(); 
                q.pop(); 
                
                if (curr -> left != NULL && curr -> right != NULL) {
                    if (curr -> left -> val == x && curr -> right -> val == y)
                        return false; 
                    
                    else if (curr -> left -> val == y && curr -> right -> val == x)
                        return false; 
                    
                    
                }
                if (curr -> left != NULL)
                    q.push(curr -> left); 
                
                if (curr -> right != NULL) 
                    q.push(curr -> right); 
                
                if (curr -> val == x)
                    xFound = true; 
                
                if (curr -> val == y)
                    yFound = true; 
                
                if (xFound == true && yFound == true)
                    return true; 
                
            }
                        
        }
        return false; 
    }
};
