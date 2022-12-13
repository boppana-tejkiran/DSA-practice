// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
        int i=0,j=m-1,count=0,maxi=0,row_num=0;
        while(i<n&&j>=0)
        {
            if(arr[i][j]==1)
            {
                count++;
                j--;
            }
            else
            {
                if(maxi<count)
                {
                    row_num = i;
                    maxi = count;
                }
                i++;
            }
        }
        if(count==m) return i;
        else if(count==0) return -1;
        else return row_num;
	}

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends