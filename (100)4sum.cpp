// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > fourSum(vector<int> &a, int k);

// Position this line where user code will be pasted.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<int> > ans = fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// arr[] : int input array of integers
// k : the quadruple sum required
vector<vector<int> > fourSum(vector<int> &arr, int k) {
    // Your code goes here
    int len = arr.size();
    sort(arr.begin(),arr.end());
    unordered_map<string,int>history;
    vector<vector<int>>out;
    for(int i=0;i<len-3;i++)
    {
        for(int j=i+1;j<len-2;j++)
        {
            int left = j+1;
            int right = len-1;
            while(left<right)
            {
                if(arr[i]+arr[j]+arr[left]+arr[right]==k)
                {
                    string temp = to_string(arr[i])+to_string(arr[j])+to_string(arr[left])+to_string(arr[right]);
                    if(history.find(temp) == history.end())
                    {
                        history[temp] = 1;
                        vector<int>row;
                        row.push_back(arr[i]); row.push_back(arr[j]); row.push_back(arr[left]); row.push_back(arr[right]);
                        out.push_back(row);
                    }
                    left++; right--;
                }
                else if(arr[i]+arr[j]+arr[left]+arr[right]<k)
                {
                    left++;
                }
                else if(arr[i]+arr[j]+arr[left]+arr[right]>k)
                {
                    right--;
                }
            }
        }
    }
    return out;
}