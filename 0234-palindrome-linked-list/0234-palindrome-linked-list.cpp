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
    
    void printList(ListNode *ptr) {
        
        if (ptr == nullptr)
            return; 
        while (ptr != nullptr){
            cout << ptr -> val  << " "; 
            ptr = ptr -> next; 
        }
    }
    ListNode* reverseList(ListNode *head) {
        ListNode *prev = nullptr, *curr = head, *next = nullptr; 
        
        while(curr != nullptr) {
            next = curr -> next; 
            curr -> next = prev; 
            prev = curr; 
            curr = next; 
        }
        return prev; 
        
    }
    bool isPalindrome(ListNode* head) {
        
        if (head == nullptr || head -> next == nullptr)
            return true; 

        ListNode *ptr = head; 
        
        //finding the middle of the list
        ListNode *slow = head, *fast = head; 
        
        while (fast -> next != nullptr && fast -> next -> next != nullptr) {
            slow = slow -> next; 
            fast = fast -> next -> next; 
        }
        // cout << slow -> val << endl; 
        // slow will point to the mid of the linked list
        // reverse the second half of the list
        ptr = reverseList(slow -> next); 
        
        
        //start comparing the nodes from beg and after middle of list
        
        ListNode *curr = head; 
        
        while (ptr != nullptr) {
            if (curr -> val != ptr -> val) 
                return false; 
            
            curr = curr -> next; 
            ptr = ptr -> next; 
        }
        
        
        
        return true; 
    }
};