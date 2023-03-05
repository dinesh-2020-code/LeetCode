
#include <algorithm>
#include <utility>
#include <vector>
#define ll long long int 
#define ln "\n"
#define pb push_back
#define ll long long int 
#define MAXOF2(x, y) (max(x, y))
#define MINOF2(x, y) (min(x, y))
 
class Solution {
public:
    
    long long kthLargestLevelSum(TreeNode* root, int k) {
        ll ans = -1; 
        priority_queue<ll> pq; 
        
        queue<TreeNode*> q; 
        q.push(root); 
        
        while (!q.empty()) {
            ll size = q.size(); 
            ll sum = (ll)0; 
            for (ll i = 0; i < size; i++) {
                TreeNode* node = q.front(); 
                q.pop(); 
                sum += ((ll)(node -> val)); 
                
                if (node -> left)
                    q.push(node -> left); 
                if (node -> right)
                    q.push(node -> right); 
            }
            pq.push(sum); 
        }
        if (!(k > pq.size())) {
            for (int i = 0; i < k-1; i++) {
                cout << pq.top();pq.pop();
            }
            ans = pq.top();
        }
        
        return ans; 
    }
};