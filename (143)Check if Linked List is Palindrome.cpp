// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/*You are required to complete this method */
Node* reverse(Node* root)
{
    if(!root) return NULL;
    Node* prev=NULL; Node* curr = root; Node* next;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node* findmid(Node* root)
{
    Node* slow=root; Node* fast=root;
    while(fast->next&&fast->next->next)
    {
        slow = slow->next; fast = fast->next->next;
    }
    return slow;
}
bool isPalindrome(Node *head)
{
    //Your code here
    Node* ptr = head;
    Node* mid = findmid(head);
    mid->next = reverse(mid->next);
    mid = mid->next;
    while(mid)
    {
        if(mid->data!=ptr->data)
        {
            return false;
        }
        mid = mid->next; ptr=ptr->next;
    }
    return true;
}

