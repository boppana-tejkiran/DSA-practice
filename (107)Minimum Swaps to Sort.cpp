// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
public:
	int minSwaps(vector<int>&nums){
	    // Code here
	    vector<pair<int,int>>myvec;
	    for(int i=0;i<nums.size();i++)
	    {
	        myvec.push_back(make_pair(nums[i],i));
	    }
	    int count=0;
	    sort(myvec.begin(),myvec.end());
	    for(int i=0;i<nums.size();i++)
	    {
	        if(myvec[i].second==i)
	        {
	            continue;
	        }
	        else
	        {
	            swap(myvec[i],myvec[myvec[i].second]);
	            count++;
	            i--;
	        }
	    }
	    return count;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends