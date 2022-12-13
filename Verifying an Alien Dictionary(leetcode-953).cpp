class Solution {
public:
    char mapp[26];
    int compare(string s1, string s2)
    {
        int res=0;
        for(int i=0;i<min(s1.length(),s2.length());i++)
        {
            if(res==0)
            {
                res = mapp[s1[i]-'a'] - mapp[s2[i]-'a'];        
            }
            else
            {
                break;
            }
        }
        if(res==0)
            return s1.length()-s2.length();
        return res;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<order.length();i++)
        {
            mapp[order[i]-'a'] = i;
        }
        for(int i=0;i<words.size()-1;i++)
        {
            if(compare(words[i],words[i+1])>0)
                return false;
        }
        return true;
    }
};