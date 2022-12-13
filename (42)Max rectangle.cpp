// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int maxArea(int M[MAX][MAX], int n, int m);
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends

int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return 0;
        if(heights.size()==1) return heights[0];
        int max_area=0,area;
        stack<int>pstack,hstack;
        int index=0;
        pstack.push(index);hstack.push(heights[index]);
        index=1;
        while(index<heights.size())
        {
            if(heights[index]>hstack.top())
            {
                hstack.push(heights[index]);
                pstack.push(index);
            }
            else if(heights[index]<hstack.top())
            {
                int temp_index,temp_height;
                while((!pstack.empty())&&(heights[index]<=hstack.top()))
                {
                    temp_index = pstack.top(); temp_height = hstack.top();
                    area = (index-temp_index)*temp_height;
                    max_area = max(max_area,area);
                    pstack.pop(); hstack.pop();
                }
                pstack.push(temp_index); hstack.push(heights[index]);
            }
            index++;
        }
        while((!hstack.empty()))
        {
            area = (index-pstack.top())*hstack.top();
            //max_area = max(area,max_area);
            if(area>max_area) max_area=area;
            hstack.pop();pstack.pop();
        }
        return max_area;
    }
/*You are required to complete this method*/
int maxArea(int M[MAX][MAX], int n, int m) {
    // Your code here
        int rows = n;
        if(rows==0) return 0;
        int cols = m;
        vector<int>loc_heights(cols,0);
        int loc_index = 0,loc_area,loc_max_area=0;
        while(loc_index<rows)
        {
            for(int i=0;i<cols;i++)
            {
                if(M[loc_index][i]==0)
                {
                    loc_heights[i] = 0;
                }
                else
                {
                    loc_heights[i]= loc_heights[i]+M[loc_index][i];
                }
            }
            loc_area = largestRectangleArea(loc_heights);
            loc_max_area = max(loc_area,loc_max_area);
            loc_index++;
        }
        return loc_max_area;
}
