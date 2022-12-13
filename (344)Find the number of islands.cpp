// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int pos1[8] = {0,0,1,-1,1,1,-1,-1};
    int pos2[8] = {1,-1,0,0,1,-1,1,-1};
    bool isvalid(vector<vector<char>>&grid, int x, int y, int row, int col)
    {
        if(x>=0 && y>=0 && x<row && y<col && grid[x][y]=='1')
            return true;
        return false;
    }
    void dfs(vector<vector<char>>&grid,int i, int j,int row, int col)
    {
        grid[i][j] = '2';
        for(int k=0;k<8;k++)
        {
            if(isvalid(grid,i+pos1[k],j+pos2[k],row,col))
            {
                dfs(grid,i+pos1[k],j+pos2[k],row,col);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int island = 0;
        int row = grid.size(); int col = grid[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1')
                {
                    island++;
                    dfs(grid,i,j,row,col);
                }
            }
        }
        return island;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends