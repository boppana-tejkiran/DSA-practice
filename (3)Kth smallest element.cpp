// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int *, int, int, int);
 
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        cout<<kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}// } Driver Code Ends


//User function template for C++

// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function
int kthSmallest(int arr[], int l, int r, int k) {
    //code here
   //Method 1: takes O(nlogn)
   //sort(arr,arr+r+1);
   //return arr[k-1];
   //Method 2: O(n) 
   //create an array of size = max element in arr then max indices of new array =1 
   // corresponding to values of arr. traverse new array and when ever it's index>0 make arr[]=index of new array
   int max=INT_MIN;
   for(int i=l;i<=r;i++)
   {
       if(max<arr[i])
       {
           max = arr[i];
       }
   }
   int* count = new int[max+1];
   for(int i=0;i<=max;i++)
   {
       count[i]=0;
   }
   for(int i=l;i<=r;i++)
   {
       count[arr[i]]++;
   }
   int count_index = 0;
   int arr_index = 0;
   while(count_index<=max)
   {
       if(count[count_index]>0)
       {
           arr[arr_index]=count_index;
           count[count_index]--;
           arr_index++;
       }
       else
       {
           count_index++;
       }
   }
   return arr[k-1];
}