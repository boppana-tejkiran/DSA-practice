#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int L,N,flag=0;
	    cin>>L; cin>>N;
	    int arr[L];
	    for(int i=0;i<L;i++)
	    {
	        cin>>arr[i];
	    }
	    sort(arr,arr+L);
	    int left=0,right=1;
	    while(left<L&&right<L)
	    {
	        if(arr[right]-arr[left]<N)
	        {
	            right++;
	        }   
	        else if(arr[right]-arr[left]>N&&left+1<right)
	        {
	            left++;
	        }
	        else if(arr[right]-arr[left]==N)
	        {
	            cout<<1<<endl; flag=1;break;
	        }
	        else
	        {
	            left++; right++;
	        }
	    }
	    if(flag==0)
	    {
	        cout<<-1<<endl;
	    }
	}
	return 0;
}