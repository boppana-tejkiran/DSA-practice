// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int allxor = 0;
        for(int i=0;i<nums.size();i++)
        {
            allxor = allxor^nums[i];
        }
        int rsm = allxor & -allxor;
        int x=0,y=0;
        for(int i=0;i<nums.size();i++)
        {
            if(!(rsm&nums[i]))
            {
                x = x^nums[i];
            }
            else
            {
                y = y^nums[i];
            }
        }
        vector<int>out;
        if(x<y)
        {
            
            out.push_back(x); out.push_back(y);
        }
        else
        {
            out.push_back(y); out.push_back(x);
        }
        return out;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends