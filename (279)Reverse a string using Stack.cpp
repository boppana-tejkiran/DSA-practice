// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        cout<<ch;
        cout<<endl;
    }
        return 0;
}

// } Driver Code Ends



//return the address of the string
char* reverse(char *S, int len)
{
    //code here
    static char* output = new char[len];
    stack<char>s;
    for(int i=0;i<len;i++)
    {
        s.push(S[i]);
    }
    for(int i=0;i<len-1;i++)
    {
        output[i]= s.top(); s.pop();
        //cout<<output[i]<<endl;
    }
    output[len-1]=s.top();
    return output;
}