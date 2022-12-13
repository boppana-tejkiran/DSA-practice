class Solution {
public:
    int specialbinsearch(vector<int>&nums,int left,int right)
    {
        while(left<right)
        {
            int mid= left+(right-left)/2;
            if(nums[mid]>nums[right])
            {
                left = mid+1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
    int binsearch(vector<int>&nums,int left,int right,int x)
    {
        
        while(left<=right)
        {
            int mid = left+(right-left)/2;
            if(nums[mid]<x)
            {
                left = mid+1;
            }
            else if(nums[mid]>x)
            {
                right = mid-1;
            }
            else if(nums[mid]==x)
            {
                return mid;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int pivot = specialbinsearch(nums,0,len-1);
        if(nums[pivot]<=target&&target<=nums[len-1])
        {
            return binsearch(nums,pivot,len-1,target);
        }
        else
        {
            return binsearch(nums,0,pivot-1,target);
        }
    }
};