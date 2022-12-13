#include <iostream>
using namespace std;

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int N,x;
	    int start,end,flag=0;
	    cin>>N; cin>>x;
	    int arr[N];
	    for(int i=0;i<N;i++)
	    {
	        cin>>arr[i];
	        if(arr[i]==x&&flag==0){start =i; flag=1;}
	        if(arr[i]==x) end = i;
	    }
	    if(x<arr[0]||x>arr[N-1]){cout<<-1<<endl;}
	    else
	    {
	        cout<<start<<" "<<end<<endl;    
	    }
	}
	return 0;
}