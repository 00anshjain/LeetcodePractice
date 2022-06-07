class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(dict.find(endWord) == dict.end())
            return 0;
        queue<string> q;
        q.push(beginWord);
        int cnt = 0;
        while(!q.empty())
        {
            int n = q.size();
            cnt++;
            while(n--)
            {
                string w = q.front();
                // q.pop();
                q.pop();
                for(int i = 0; i < w.size(); i++)
                {
                    char k = w[i];
                    for(char j = 'a'; j <= 'z'; j++)
                    {
                        if(j == k)
                            continue;
                        w[i] = j;
                        if(dict.find(w) != dict.end())
                        {
                            if(w == endWord)
                                return cnt+1;
                            q.push(w);
                            dict.erase(dict.find(w));
                        }
                    }
                    w[i] = k;
                }
            }
        }
        return 0;
    }
};