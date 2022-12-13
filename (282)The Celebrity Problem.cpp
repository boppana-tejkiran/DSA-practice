// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
    public:
    int celebrity(vector<vector<int> >& M, int n) {
        // code here
        int left=0,right=n-1;
        while(left<right)
        {
            if(!M[left][right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(M[left][i])
            {
                return -1;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i!=left)
            {
                if(M[i][left]==0)
                {
                    return -1;
                }
            }
        }
        return left;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends