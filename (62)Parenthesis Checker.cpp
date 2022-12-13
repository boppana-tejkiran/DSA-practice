// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to return if the paranthesis are balanced or not
bool ispar(string x)
{
    // Your code here
    stack<char>s;
    for(int i=0;i<x.length();i++)
    {
        if(s.empty())
        {
            s.push(x[i]);
        }
        else
        {
            //cout<<x[i]<<" ";
            if(s.top()=='(' && x[i]==')')
            {
                s.pop();
            }
            else if(s.top()=='{' && x[i]=='}')
            {
                s.pop();
            }
            else if(s.top()=='[' && x[i]==']')
            {
                s.pop();
            }
            else
            {
                s.push(x[i]);
            }
        }
    }
    if(s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}


// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       if(ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends