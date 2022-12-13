// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>output;
    int visited[10][10];
    void helper(vector<vector<int>> &m,int x,int y,int n,vector<vector<int>>&visited,string s)
    {
        if(x<0 || y<0) return;
        if(x>=n || y>=n) return;
        if(m[x][y]==0) return;
        if(visited[x][y]==1) return;
        if(x==n-1 && y==n-1)
        {
            output.push_back(s);
            return;
        }
        
        visited[x][y] = 1;
        
        helper(m,x,y+1,n,visited,s+'R');
        
        helper(m,x,y-1,n,visited,s+'L');
        
        helper(m,x-1,y,n,visited,s+'U');

        helper(m,x+1,y,n,visited,s+'D');
        
        visited[x][y] = 0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        if(m[0][0]==0)
        {
            return output;
        }
        if(m[n-1][n-1]==0)
        {
            return output;
        }
        vector<vector<int>>visited(n,vector<int>(n));
        // memset(visited,0,n*n);
        string s="";
        helper(m,0,0,n,visited,s);
        sort(output.begin(),output.end());
        return output;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends