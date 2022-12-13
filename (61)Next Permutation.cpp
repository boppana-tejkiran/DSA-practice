// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int i;
        //step:1 finding the dip
        for(i=N-1;i>0;i--)
        {
            if(arr[i]>arr[i-1])
            {
                break;
            }
        }
        i--;
        //cout<<arr[i]<<endl;
        if(i<0)
        {
            reverse(arr.begin(),arr.end());
            return arr;
        }
        //step:2  finding next big element
        int mini=INT_MAX,victim,j;
        for(int j=N-1;j>i;j--)
        {
            if(arr[j]>arr[i])
            {
                if(arr[j]<=mini)
                {
                    mini = arr[j]; victim = j;
                }
            }
        }
        //step:3 swap dip and next big element
        swap(arr[i],arr[victim]);
        //for(int z=0;z<arr.size();z++) cout<<arr[z]<<"\n";
        //cout<<"i:"<<i<<endl;
        //step 4: reverse rest of the string from dip 
        reverse(arr.begin()+i+1,arr.end());
        return arr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends