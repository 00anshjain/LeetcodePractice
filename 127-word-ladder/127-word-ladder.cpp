class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(dict.find(endWord) == dict.end())
            return 0;
        if(beginWord == endWord)
            return 0;
        queue<string> q;
        q.push(beginWord);
        int t = 1;
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                string word = q.front();
                q.pop();
                for(int i = 0; i < word.size(); i++)
                {
                    char k = word[i];
                    for(char j = 'a'; j <= 'z'; j++)
                    {
                        if(j == k)
                            continue;
                        word[i] = j;
                        if(dict.find(word) != dict.end())
                        {
                            if(word == endWord)
                                return t + 1;
                            q.push(word);
                            auto itr = dict.find(word);
                            dict.erase(itr);
                        }
                    }
                    word[i] = k;
                }
            }
            t++;
        }
        return 0;
    }
};