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
private: 
    vector<int> v;
    vector<int> pPath, qPath; 
    bool found; 
    
    void dfs(TreeNode * root, TreeNode *p, TreeNode *q) {
        if (root == NULL  || found == true)
            return; 
        
        v.push_back(root -> val); 
        if (root -> val == p -> val) {
            for (int i = 0; i < v.size(); i++) {
                pPath.push_back(v[i]); 
            }
             
        }
        if (root -> val == q -> val) {
            for (int i = 0; i < v.size(); i++) {
                qPath.push_back(v[i]); 
            }
            
        }
        dfs(root -> left, p, q); 
        dfs(root -> right, p, q);
        v.pop_back(); 
    }
    void print(vector<int> &v) {
        for (auto it : v) 
            cout << it << " "; 
        
        cout << endl; 
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (root == NULL)
            return root; 
        
        found = false; 
        dfs(root, p, q); 
        
        print(pPath); 
        print(qPath); 
        int i = 0, j = 0;
        for (; i < pPath.size() && j < qPath.size(); ) {
            if (pPath[i] != qPath[j]) {
                return new TreeNode(pPath[i-1]); 
            }
            i++, j++; 
        }
        return new TreeNode(pPath[i-1]); 
    }
};