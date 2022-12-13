// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        stack<char>cstack;
        stack<int>istack;
        istack.push(-1);
        int maxi =0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                cstack.push('('); istack.push(i);
            }
            else
            {
                if(!cstack.empty()&&cstack.top()=='(')
                {
                    cstack.pop(); istack.pop(); maxi = max(maxi,i-istack.top());
                }
                else
                {
                    istack.push(i);
                }
            }
        }
        return maxi;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends