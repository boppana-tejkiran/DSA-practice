// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool helper(int v, bool visited[], int p, vector<int>adj[])
    {
        visited[v] = true;
        for(auto i=adj[v].begin();i!=adj[v].end();i++)
        {
            if(!visited[*i])
            {
                if(helper(*i,visited,v,adj))
                    return true;
            }
            else
            {
                if(*i!=p)
                {
                    return true;
                }
            }
        }
        return false;
    }
	bool isCycle(int V, vector<int>adj[]){
	    // Code here
	    bool *visited = new bool[V];
	    for(int i=0;i<V;i++)
	    {
	        visited[i] = false;
	    }
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	        {
	            if(helper(i,visited,-1,adj))
	            {
	                return true;
	            }
	        }
	    }
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends