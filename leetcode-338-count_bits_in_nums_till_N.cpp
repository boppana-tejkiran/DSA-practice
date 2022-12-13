class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>output;
        output.push_back(0);
        for(int i=1;i<=num;i++)
        {
            if(i%2)
            {
                output.push_back(output[i/2]+1);
            }
            else
            {
                output.push_back(output[i/2]);
            }
        }
        return output;
    }
};