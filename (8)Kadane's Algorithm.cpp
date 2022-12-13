// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n){
    
    // Your code here
    int max_sum=arr[0];
    int temp_sum = arr[0];
    //kadane's algorithm 
    for(int i=1;i<n;i++)
    {
        temp_sum = max(arr[i],temp_sum+arr[i]);
        if(temp_sum>max_sum)
        {
            max_sum = temp_sum;
        }
    }
    return max_sum;
}

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends