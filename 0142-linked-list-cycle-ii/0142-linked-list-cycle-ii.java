/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        //detecting cycle
        ListNode slow = head, fast = head;
        boolean isLoop = false;
        while (fast != null  && fast.next != null) {
            slow = slow.next ; 
            fast = fast.next.next; 

            if (slow == fast) {
                isLoop = true; 
                break; 
            }        
        }

        if (!isLoop) 
            return null; 

        //detecting the first node of the loop
        slow = head; 
        while (slow != fast) {
            slow = slow.next; 
            fast = fast.next ; 
        }   
        return slow;  
    }
}