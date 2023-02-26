//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:
    Node *reverseList(Node *head) {
        if (head == nullptr || head -> next == nullptr)
            return head; 
            
        Node *newHead = reverseList(head->next); 
        head -> next -> next = head; 
        head -> next = nullptr; 
        return newHead; 
    }
    void print(Node *head) {
        while (head != nullptr)
        {
            cout << head -> data << " -> ";
            head = head -> next; 
        }
        cout << "NULL";
        cout << endl;
    }
    Node *reverse(Node *head, int k)
    {
        Node *first = head, *second = nullptr; 
        Node *curr = head; 
        int i = 1; 
        Node *temp = first; 
        for (; first != nullptr && curr != NULL && i < k; i++) {
            
            temp -> next = curr -> next; 
            curr = curr -> next; 
            temp = temp -> next; 
        }
        curr = temp; 
        if (curr)
            second = curr -> next; 
        
        temp -> next = NULL; 
        
        Node *p1 = reverseList(first); 
        Node *p2 = reverseList(second) ;
        
        first -> next = p2; 
        
        return p1; 
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends