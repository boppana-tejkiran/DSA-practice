/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node, Node* clone, vector<Node*>&visited)
    {
        visited[clone->val] =  clone;  //set visited of clone[val] = name of the vertex to its address
        for(auto x: node->neighbors) // now do dfs on node's neighbors
        {
            if(visited[x->val]==NULL) //if  neighbor is not visited
            {
                Node* newnode = new Node(x->val); //create a new node whose value = x->val = neighbor's name
                clone->neighbors.push_back(newnode); //make it neighbor of clone
                dfs(x,newnode,visited); //call dfs on neighbor now
            }
            else //if the neighbor of node is already visited, just add it to clone's neighbor
            {
                clone->neighbors.push_back(visited[x->val]);
            }
        }
        
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL; //node is pointer to first graph. Checking if it is null. If null, simply return NULL
        vector<Node*>visited(1000,NULL); //create a visited vector. It contains the address  of nodes in graph
        Node* clone = new Node(node->val);  //create first node and assign its value = node->val
        dfs(node,clone,visited); //call dfs on this node, also bring clone pointer (first node to our new graph) and visited matrix
        return clone; //return clone, the first pointer to the new clone graph 
    }
};