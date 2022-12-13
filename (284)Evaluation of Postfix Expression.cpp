// { Driver Code Starts
// C++ program to evaluate value of a postfix expression
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// The main function that returns value of a given postfix expression
int evaluatePostfix(string S)
{
    // Your code here
    stack<int>s;
    for(int i=0;i<S.length();i++)
    {
        if((S[i]-'0')>=0&&(S[i]-'0')<=9)
        {
            // cout<<(S[i]-'0')<<" ";
            s.push(S[i]-'0');
        }
        else
        {
            //cout<<S[i]<<" ";
            int temp1 = s.top(); s.pop();
            int temp2 = s.top(); s.pop();
            switch(S[i])
            {
                case '+': s.push(temp1+temp2); break;
                case '-': s.push(temp2-temp1); break;
                case '*': s.push(temp1*temp2); break;
                case '/': s.push(temp2/temp1); break;
            }
        }
    }
    return s.top();
}


// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
    
    cout<<evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends