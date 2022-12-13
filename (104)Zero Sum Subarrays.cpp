// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>

using namespace std;

#define ll long long 
ll findSubarray(vector<ll> , int );

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        
        cout << findSubarray(arr,n) << "\n";
    }
	return 0;
}// } Driver Code Ends


//User function template for C++

// arr : given array 
// n : size of the given array
ll findSubarray(vector<ll> arr, int n ) {
    //code here
    if(!n) return 0;
    unordered_map<ll,ll>mymap;
    ll currsum=0;
    ll count = 0;
    for(ll i=0;i<n;i++)
    {
        currsum+=arr[i];
        if(currsum==0)
        {
            count++;
        }
        if(mymap.find(currsum)!=mymap.end())
        {
            count+=mymap[currsum];
        }
        mymap[currsum]++;
    }
    return count;
}
