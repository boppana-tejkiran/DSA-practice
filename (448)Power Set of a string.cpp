// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
        void powerset(string input, string output, vector<string>&permute)
        {
            if(input.length()==0)
            {
                permute.push_back(output);
            }
            else
            {
                string op1 = output; string op2 = output;
                op2 = op2+input[0];
                input.erase(input.begin());
                powerset(input,op1,permute); powerset(input,op2,permute);
            }
        }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    string input = s;
		    string output = "";
		    vector<string>permute;
		    powerset(input,output,permute);
		    sort(permute.begin(),permute.end());
		    permute.erase(permute.begin());
		    return permute;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends