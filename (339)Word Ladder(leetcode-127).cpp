class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>myset;
        bool ispresent=false;
        for(auto w: wordList)
        {
            if(endWord.compare(w)==0)
                ispresent = true;
            myset.insert(w);
        }
        if(!ispresent)
            return 0;
        queue<string>q;
        q.push(beginWord);
        int depth = 0;
        while(!q.empty())
        {
            depth++;
            int levelsize = q.size();
            while(levelsize--)
            {
                string curr = q.front();
                q.pop();
                for(int i=0;i<curr.size();i++)
                {
                    string temp = curr;
                    for(char c='a'; c<='z'; c++)
                    {
                        temp[i] = c;
                        if(curr.compare(temp)==0)
                            continue;
                        else if(temp.compare(endWord)==0)
                            return (depth+1);
                        else if(myset.find(temp)!=myset.end())
                        {
                            q.push(temp); myset.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};