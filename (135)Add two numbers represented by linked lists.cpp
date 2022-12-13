// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

struct Node* addTwoLists(struct Node* first, struct Node* second);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends


/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
struct Node* reverse(struct Node* head)
{
    struct  Node *prev,*next,*curr;
    prev=NULL; curr=head; next=NULL;
    while(curr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    // code here
    first = reverse(first);
    second = reverse(second);
    int v1,v2,sum=0,carry=0;
    struct Node* origin = new Node(-1);
    struct Node* ptr = origin;
    while(first||second)
    {
        if(first)
        {
            v1=first->data;
            first=first->next;
        }
        else
        {
            v1=0;
        }
        if(second)
        {
            v2=second->data;
            second=second->next;
        }
        else
        {
            v2=0;
        }
        sum=v1+v2+carry;carry=sum/10; sum=sum%10;
        struct Node* temp = new Node(sum); ptr->next=temp; ptr=ptr->next;
    }
    if(carry)
    {
        struct Node* temp = new Node(carry); ptr->next=temp;
    }
    //return NULL;
    return reverse(origin->next);
}
