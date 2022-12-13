/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin>>N; int arr[N];
	for(int i=0;i<N;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+N); 
	int sum[N]; sum[0]=arr[0];
	for(int i=1;i<N;i++)
	{
		sum[i] = sum[i-1]+arr[i];
	}
	int Q; cin>>Q; 
	for(int i=1;i<=Q;i++)
	{
		int P; cin>>P; int j=0; int flag=0;
		for(j=0;j<N;j++)
		{
			if(arr[j]>P)
			{
				cout<<j<<" "<<sum[j-1]<<endl; flag=1;
				break;
			}
		}
		if(flag==0)
		{
			j=N; cout<<j<<" "<<sum[j-1]<<endl;
		}
	}
	return 0;
}