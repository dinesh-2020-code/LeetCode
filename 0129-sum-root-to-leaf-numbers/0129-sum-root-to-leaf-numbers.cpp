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
    int sumNumbers(TreeNode* root) {
        
        queue<TreeNode*> q; 
        queue<int> value; 
        
        q.push(root); 
        value.push(0); 
        
        int ans = 0; 
        while (!q.empty()) {
            TreeNode* curr = q.front(); 
            q.pop(); 
            int currVal = value.front(); 
            value.pop(); 
            
            if ((curr -> left == NULL && curr -> right == NULL)) {
                ans += (currVal * 10 + curr -> val); 
            }
            if (curr -> left) {
                q.push(curr -> left);
                value.push(currVal * 10 + curr -> val); 
            }
            if (curr -> right) {
                q.push(curr -> right) ;
                value.push(currVal * 10 + curr -> val); 
            }
        }
        return ans; 
    }
};