// { Driver Code Starts

#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends



class Solution
{   
public:
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int direction = 0;
        int left=0,right=c-1;
        int up=0,down=r-1;
        vector<int>result;
        while((left<=right)&&(up<=down))
        {
             if(direction==0)
            {
                for(int i=left;i<=right;i++)
                {
                    result.push_back(matrix[up][i]);
                }
                up++;
            }
            else if(direction==1)
            {
                for(int i=up;i<=down;i++)
                {
                    result.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(direction==2)
            {
                for(int i=right;i>=left;i--)
                {
                    result.push_back(matrix[down][i]);
                }
                down--;
            }
            else if(direction==3)
            {
                for(int i=down;i>=up;i--)
                {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
            direction = (direction+1)%4;
        }
        return result;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends