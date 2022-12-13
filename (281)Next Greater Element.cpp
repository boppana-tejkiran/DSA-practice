// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Next larger elements


vector<long long> nextLargerElement(vector<long long> arr, int n){
    // Your code here
    vector<long long>output(n);
    stack<int>s;
    s.push(0);
    for(int i=1;i<n;i++)
    {
        if(arr[i]<arr[s.top()])
        {
            s.push(i);
        }
        else
        {
            while((!s.empty())&&(arr[s.top()]<arr[i]))
            {
                output[s.top()]=arr[i];
                s.pop();   
            }
            s.push(i);
        } 
    }
    while(!s.empty())
    {
        output[s.top()] = -1;
        s.pop();
    }
    return output;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        
        vector <long long> res = nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
  // } Driver Code Ends