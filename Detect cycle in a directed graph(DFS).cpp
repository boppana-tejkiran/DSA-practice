// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool helper(int v, bool visited[],bool recstack[], vector<int> adj[])
    {
        if(!visited[v])
        {
            visited[v] = true; recstack[v] = true;
            for(auto i=adj[v].begin(); i!=adj[v].end();i++)
            {
                if(!visited[*i] && helper(*i,visited,recstack,adj))
                {
                    return true;
                }
                else
                {
                    if(recstack[*i])
                        return true;
                }
            }
        }
        recstack[v] = false;
        return false;
    }
	bool isCyclic(int V, vector<int> adj[]) {
	   	// code here
	   	bool *visited = new bool[V];
	   	bool *recstack = new bool[V];
	   	for(int i=0;i<V;i++)
	   	{
	   	    visited[i] = false; recstack[i] = false;
	   	}
	   	for(int i=0;i<V;i++)
	   	{
	   	    if(helper(i,visited,recstack,adj))
	   	    {
	   	        return true;
	   	    }
	   	}
	   	return false;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends