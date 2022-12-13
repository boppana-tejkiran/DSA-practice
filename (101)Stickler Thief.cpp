// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


 // } Driver Code Ends
// Function to return maximum of sum without adjacent elements
ll FindMaxSum(ll arr[], ll n)
{
    // Your code here
    ll ex_prev=0,in_prev=0,ex_curr,in_curr;
    for(ll i=0;i<n;i++)
    {
        ex_curr = max(in_prev,ex_prev);
        in_curr = ex_prev+arr[i];
        ex_prev = ex_curr;
        in_prev = in_curr;
    }
    return max(in_curr,ex_curr);
}


// { Driver Code Starts.

int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		ll n;
		cin>>n;
		ll a[n];
		
		//inserting money of each house in the array
		for(ll i=0;i<n;++i)
			cin>>a[i];
			
		//calling function FindMaxSum()
		cout<<FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends