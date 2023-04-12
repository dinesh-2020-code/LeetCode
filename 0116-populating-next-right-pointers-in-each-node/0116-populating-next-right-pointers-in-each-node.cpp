/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private: 
    void dfs(Node *left, Node *right) {
        if (left == NULL)
            return; 
        
        left -> next = right; 
        dfs(left -> left, left -> right); 
        dfs(left -> right, right -> left);
        dfs(right -> left, right -> right);
    }
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return root; 
        
        dfs(root -> left, root -> right); 
        return root; 
    }
};