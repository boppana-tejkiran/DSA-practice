// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int>&, int );

// your code will be pasted here

int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        
        vec = productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}// } Driver Code Ends


//User function template for C++

// nums: given vector
// return the Product vector P that hold product except self at each index
vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
   
    //code here 
    vector<long long int>output;
    if(n==1)
    {
        output.push_back(1);
        return output;
    }
    long long int leftprod[n]; leftprod[0]=nums[0];
    long long int rightprod[n]; rightprod[0]=nums[n-1];
    
    for(int i=1;i<n;i++)
    {
        leftprod[i]=leftprod[i-1]*nums[i];
    }
    for(int i=1; i<n; i++)
    {
        rightprod[i]=rightprod[i-1]*nums[n-1-i];
    }
    output.push_back(rightprod[n-2]);
    for(int i=1;i<n-1;i++)
    {
        output.push_back(leftprod[i-1]*rightprod[n-1-i-1]);   
    }
    output.push_back(leftprod[n-2]);
    return output;
}
