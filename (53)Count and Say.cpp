class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        string result="11";
        for(int i=3;i<=n;i++)
        {
            string temp="";
            int count = 1;
            for(int j=1;j<=result.length();j++)
            {
                if(result[j]==result[j-1])
                {
                    count++;
                }
                else
                {
                    temp = temp+to_string(count);
                    temp = temp+result[j-1];
                    count = 1;
                }
            }
            result = temp;
        }
        return result;
    }
};