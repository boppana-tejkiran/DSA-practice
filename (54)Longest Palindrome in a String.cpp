#include <bits/stdc++.h>
using namespace std;

string longpal;
void count(string S,int start,int end)
{
    while((start>=0) && (end<S.length()) && (S[start]==S[end]))
    {
        string temp = S.substr(start,(end-start+1));
        if(temp.size()>longpal.size())
        {
            longpal = temp;
        }
        start--; end++;
    }
}
void longestpalindrome(string S)
{
    for(int i=0;i<S.length();i++)
    {
        count(S,i,i);
        count(S,i,i+1);
    }
}

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    string S;
	    string temp="hello world";
	    cin>>S;
	    longpal = S[0];
	    longestpalindrome(S);
	    
	    cout<<longpal;
	    cout<<endl;
	}
	return 0;
}