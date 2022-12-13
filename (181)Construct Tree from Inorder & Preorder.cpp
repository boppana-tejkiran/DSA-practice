// { Driver Code Starts
//

#include<bits/stdc++.h>
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

Node *buildTree(int inorder[], int preorder[], int n);

void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		
		Node *root = buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
map<int,int>mymap;
Node* helper(int prestart,int in[],int pre[],int low,int high,int n)
{
    if((low>high)||(prestart>n-1)) return NULL;
    Node* res = new Node(pre[prestart]);
    res->left=helper(prestart+1,in,pre,low,mymap[res->data]-1,n);
    res->right = helper(prestart+mymap[res->data]-low+1,in,pre,mymap[res->data]+1,high,n);
    return res;
}
Node* buildTree(int in[],int pre[], int n)
{
//add code here.
    mymap.clear();
    
    for(int i=0;i<n;i++)
    {
        mymap[in[i]]=i;
    }
    return helper(0,in,pre,0,n-1,n);
}