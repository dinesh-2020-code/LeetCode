/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode * head = NULL; 
    vector<int> v; 
    Solution(ListNode* head) {
        this -> head = head; 
    }
    
    int getRandom() {
        int scope = 1, chosenValue = 0; 
        ListNode *curr = nullptr; 
        curr = this -> head; 
        while (curr != NULL) {
            if ((double)rand() / RAND_MAX < 1.0 / scope)
                chosenValue = curr -> val; 
            
            scope += 1; 
            curr = curr -> next; 
        }
        return chosenValue;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */