// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
void sort012(int[],int);

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

// } Driver Code Ends


void sort012(int a[], int n)
{
    // code here 
    int arr[3]={0};
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            arr[0]++;
        }
        else if(a[i]==1)
        {
            arr[1]++;
        }
        else if(a[i]==2)
        {
            arr[2]++;
        }
    }
    int arr_index = 0,a_index=0;
    while(arr_index<3)
    {
        if(arr[arr_index]>0)
        {
            a[a_index]=arr_index;
            a_index++;
            arr[arr_index]--;
        }
        else
        {
            arr_index++;
        }
    }
}