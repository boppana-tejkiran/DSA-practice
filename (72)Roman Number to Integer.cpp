// { Driver Code Starts
// Initial template for C++

// Program to convert Roman Numerals to Numbers
#include <bits/stdc++.h>
using namespace std;

// Returns decimal value of roman numaral
int romanToDecimal(string &);

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << romanToDecimal(s) << endl;
    }
}// } Driver Code Ends


// User fuunction teemplate for C++

// str given roman number string
// Returns decimal value of roman numaral
int romanToDecimal(string &str) {
    // code here
    int prev=0,current=0;
    map<char,int>MP;
    MP['I']=1;MP['V']=5;MP['X']=10;MP['L']=50;MP['C']=100;MP['D']=500;MP['M']=1000;
    int sum=0;
    for(int i=str.length()-1;i>=0;i--)
    {
        current = MP[str[i]];
        //cout<<"current:"<<current<<endl;
        if(current>=prev)
        {
            sum+=current;
            //cout<<"here"<<endl;
        }
        else
        {
            sum-=current;
        }
        prev = current;
    }
    return sum;
}