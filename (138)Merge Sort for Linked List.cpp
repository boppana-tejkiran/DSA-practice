// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends


/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

/* Function to mergesort the linked list
   It should return head of the modified list  */
Node* midfind(Node* root)
{
    if(!root||!root->next) return root;
    Node* slow=root; Node* fast = root;
    while(fast->next&&fast->next->next)
    {
        slow = slow->next; fast = fast->next->next;
    }
    return slow;
}
Node* mergeLL(Node* l1, Node* l2)
{
    if(!l1||!l2) return l1!=NULL? l1:l2;
    Node* temp1=l1; Node* temp2=l2; Node* origin = new Node(-1); Node* ptr = origin;
    while(temp1&&temp2)
    {
        if(temp1->data<temp2->data)
        {
            ptr->next = temp1; temp1=temp1->next;
        }
        else
        {
            ptr->next = temp2; temp2=temp2->next;
        }
        ptr=ptr->next;
    }
    ptr->next = temp1? temp1:temp2;
    return origin->next;
}
Node* mergeSort(Node* head) {
    // your code here
    if(!head||!head->next) return head;
    Node* mid = midfind(head);
    Node* newhead = mid->next;
    mid->next = NULL;
    return mergeLL(mergeSort(head),mergeSort(newhead));
}


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends