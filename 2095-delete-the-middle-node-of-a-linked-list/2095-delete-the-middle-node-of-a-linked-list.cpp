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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp = head; 
        
        //if Linked list is empty OR linked list  contains one node
        
        if (head == NULL || head -> next == nullptr) 
        {
            temp = head; 
            head = nullptr; 
            delete (temp);
            return head; 
        }
        
        ListNode *slow = head, *fast = head; 
        
        while (fast -> next != nullptr && fast -> next -> next != nullptr && fast -> next -> next -> next != nullptr) 
        {
            slow = slow -> next; 
            fast = fast -> next -> next; 
        }
        
        temp = slow -> next; 
        slow -> next = slow -> next -> next;
        
        delete (temp); 
        return head; 
    }
};