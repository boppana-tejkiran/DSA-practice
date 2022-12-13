// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node* root = newNode(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current node
			currNode->left = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}


int getCount(Node *root, int low, int high);
int main()
{
	
	int t;
	scanf("%d ", &t);
	while (t--)
	{
		string s;
		getline(cin >> ws, s);
		int l, r;
		cin >> l >> r;
		
		Node* root = buildTree(s);
		cout << getCount(root, l, r) << endl;
		
	}
	return 1;
}
// } Driver Code Ends


/*

The structure of a BST node is as follows:

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/
void inorder(Node* root,vector<int>&output)
{
    if(!root) return;
    if(root->left)
    {
        inorder(root->left,output);
    }
    output.push_back(root->data);
    if(root->right)
    {
        inorder(root->right,output);
    }
}
int getCount(Node *root, int l, int h)
{
  // your code goes here 
  vector<int>output;
  inorder(root,output);
  int low=0,high=output.size()-1;
  if(l>output[output.size()-1]) return 0;
  if(l==h&&h==output[output.size()-1]) return 1;
  if(l==output[output.size()-1]&&h>output[output.size()-1]) return 1;
  for(int i=0;i<output.size();i++)
  {
      if(output[i]>=l)
      {
          low=i;
          break;
      }
  }
  high=low;
  for(int i=output.size()-1;i>=low;i--)
  {
      if(output[i]<=h)
      {
          high = i;
          break;
      }
  }
 
  if(high==low&&output[high]>h) return 0;
  return (high-low+1);
}

