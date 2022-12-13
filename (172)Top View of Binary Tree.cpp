// { Driver Code Starts
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

vector<int> topView(struct Node *root);


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        vector<int> res = topView(root);
        
        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}




// } Driver Code Ends


//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree

vector<int> topView(struct Node *root)
{
    //Your code here
    vector<int>output;
    if(!root) return output;
    map<int,Node*>mymap;
    queue<pair<Node*,int>>myqu;
    myqu.push(make_pair(root,0));
    while(!myqu.empty())
    {
        pair<Node*,int>temp = myqu.front();
        myqu.pop();
        if(mymap.find(temp.second)==mymap.end())
        {
            mymap[temp.second] = temp.first;
        }
        if(temp.first->left)
        {
            myqu.push(make_pair(temp.first->left,temp.second-1));
        }
        if(temp.first->right)
        {
            myqu.push(make_pair(temp.first->right,temp.second+1));
        }
    }
    map<int,Node*>::iterator it;
    for(it=mymap.begin();it!=mymap.end();it++)
    {
        output.push_back(it->second->data);
    }
    return output;
}


