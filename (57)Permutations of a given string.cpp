#include<bits/stdc++.h>
#include <iostream>
using namespace std;
vector<string>store;
void permutate(string s, int left, int right)
{
    if(left==right)
    {
        store.push_back(s);
    }
    else
    {
        for(int i=left;i<=right;i++)
        {
            swap(s[left],s[i]);
            permutate(s,left+1,right);
            swap(s[left],s[i]);
        }
    }
}
int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    string s;
	    cin>>s;
	    store.clear();
	    int left=0,right=s.length()-1;
	    permutate(s,left,right);
	    sort(store.begin(),store.end());
	    for(int i=0;i<store.size();i++)
	    {
	        cout<<store[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}