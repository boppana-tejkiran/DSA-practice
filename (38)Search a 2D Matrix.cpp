class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int cols = matrix[0].size();
        int rows = matrix.size();
        int up = 0,down = rows-1,mid;
        int left=0,right=cols-1;
        if((up==down)&&(left==right))
        {
            if(matrix[0][0]==target)
            {
                return true;
            }
        }
        while(up<=down)
        {
            mid = up+(down-up)/2;
            if(matrix[mid][cols-1]<target)
            {
                up = mid+1;
            }
            else if(matrix[mid][cols-1]>target)
            {
                down = mid-1;
            }
            else if(matrix[mid][cols-1]==target)
            {
                return true;
            }
        }
        int temp;
        if(up>=rows) temp = down;
        else temp = up;
        while(left<=right)
        {
            mid = left+(right-left)/2;
            if(matrix[temp][mid]<target)
            {
                left = mid+1;
            }
            else if(matrix[temp][mid]>target)
            {
                right = mid-1;
            }
            else if(matrix[temp][mid]==target)
            {
                return true;
            }
        }
        return false;
    }
};