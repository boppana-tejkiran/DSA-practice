// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int largestBst(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       //getline(cin, s);
      // int k = stoi(s);
       // getline(cin, s);

       cout << largestBst(root1);
        cout << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}// } Driver Code Ends


/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST
tuple<int,int,int,int> postorder(Node* root,int &res)
{
    if(!root)
    {
        return make_tuple(1,INT_MAX,INT_MIN,0);
    }
    tuple<int,int,int,int>l_out = postorder(root->left,res);
    tuple<int,int,int,int>r_out = postorder(root->right,res);
    if(get<0>(l_out)&&get<0>(r_out)&&root->data>get<2>(l_out)&&root->data<get<1>(r_out))
    {
        res = max(res,(get<3>(l_out)+get<3>(r_out)+1));
        if(get<1>(l_out)==INT_MAX)
        {
            get<1>(l_out) = root->data;
        }
        if(get<2>(r_out)==INT_MIN)
        {
            get<2>(r_out) = root->data;
        }
        return make_tuple(1,get<1>(l_out),get<2>(r_out),(get<3>(l_out)+get<3>(r_out)+1));
    }
    else
    {
        return make_tuple(0,INT_MAX,INT_MIN,0);
    }
    
}
int largestBst(Node *root)
{
	//Your code here
	int res=0;
	postorder(root,res);
	return res;
}