// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isvalid(int x, int y, int N, vector<vector<int>>&board)
    {
        if((x>=0&&y>=0 && x<=(N-1) && y<=(N-1)) && (board[x][y]==-1))
            return true;
        return false;
    }
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    queue<pair<int,int>>q;
	    q.push({KnightPos[0]-1,KnightPos[1]-1});
	    vector<vector<int>>board(N,vector<int>(N,-1));
	    board[KnightPos[0]-1][KnightPos[1]-1] = 0;
	    int pos1[8] = {2,1,-1,-2,2,1,-1,-2};
	    int pos2[8] = {1,2,2,1,-1,-2,-2,-1};
	    while(!q.empty())
	    {
	        pair<int,int>temp = q.front();
	        q.pop();
	        for(int i=0;i<8;i++)
	        {
	            if(isvalid(temp.first+pos1[i],temp.second+pos2[i],N,board))
	            {
	                q.push({temp.first+pos1[i],temp.second+pos2[i]});
	                board[temp.first+pos1[i]][temp.second+pos2[i]] = 1 + board[temp.first][temp.second];
	            }
	        }
	    }
	    return board[TargetPos[0]-1][TargetPos[1]-1];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends