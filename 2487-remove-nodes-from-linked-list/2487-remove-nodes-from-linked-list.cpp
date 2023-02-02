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
    ListNode* reverse(ListNode*head) {
        ListNode* curr = head, *temp = head,  *prev = nullptr; 
        
        while (temp != nullptr) {
            curr = temp; 
            temp = temp -> next; 
            curr -> next = prev; 
            prev = curr; 
        }
        return prev; 
        
    }
    ListNode* addAtHead(ListNode *ptr, int data) {
        ListNode* NEW = nullptr; 
        if (ptr == NULL){ // Linked list is empty
            NEW = new ListNode(data);
            return NEW; 
        }
        else {
            NEW = new ListNode(data); 
            NEW -> next = ptr; 
            ptr = NEW; 
        }
        return ptr;
    } 
    ListNode* removeNodes(ListNode* head) {
        ListNode *rev = reverse(head); 
        
        ListNode *ans = NULL;  
        ListNode *temp = (rev);
        int maxi = INT_MIN; 
        while (temp != nullptr) {
            if (temp -> val >= maxi) {
                maxi = temp->val; 
                
                ans = addAtHead(ans, temp -> val) ; 
            }
            temp = temp -> next; 
        }
        return ans; 
    }
};