// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<int>bfsOfGraph(int V, vector<int> adj[]){
	    // Code here
	    bool visited[V];
	    for(int i=0;i<V;i++) visited[i] = false;
	    queue<int>q;
	    q.push(0);
	    vector<int>output;
	    while(!q.empty())
	    {
	        int temp = q.front();
	        output.push_back(temp);
	        visited[temp] = true;
	        q.pop();
	        for(auto i=adj[temp].begin();i!=adj[temp].end();i++)
	        {
	            if(visited[*i]==false)
	            {
	                q.push(*i); visited[*i]=true;
	            }
	        }
	    }
	    return output;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends