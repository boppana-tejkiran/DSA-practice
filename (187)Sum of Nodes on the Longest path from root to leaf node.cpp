// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


int sumOfLongRootToLeafPath(Node* root);

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout<<sumOfLongRootToLeafPath(root)<<endl;
  }
  return 0;
}// } Driver Code Ends


//User function Template for C++
/*
structure of the node of the binary tree is as
struct Node {
	int data;
	Node* left, *right;
};
*/
// your task is to complete this function
void helper(Node* root,int sum,int len, int &max_sum, int &max_len)
{
    if(!root)
    {
        if(len>max_len)
        {
            max_len = len; max_sum=sum;
        }
        else if((len==max_len)&&(sum>max_sum))
        {
            max_sum=sum;
        }
        return;
    }
    helper(root->left,root->data+sum,len+1,max_sum,max_len);
    helper(root->right,root->data+sum,len+1,max_sum,max_len);
}
int sumOfLongRootToLeafPath(Node* root)
{
	// Code here
	if(!root) return 0;
	int max_sum=INT_MIN,max_len=0;
	helper(root,0,0,max_sum,max_len);
	return max_sum;
}