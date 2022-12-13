// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int a[], int size)
{
    // your code here
    int count=0,maj;
    for(int i=0;i<size;i++)
    {
        if(count==0)
        {
            maj = a[i]; count=1;
        }
        else
        {
            if(a[i]!=maj)
            {
                count--;
            }
            else if(a[i]==maj)
            {
                count++;
            }
        }
    }
    count = 0;
    for(int i=0;i<size;i++)
    {
        if(a[i]==maj)
        {
            count++;
        }
    }
    if(count>size/2)
    {
        return maj;
    }
    else
    {
        return -1;
    }
}

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        cout << majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends