class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(dict.find(endWord) == dict.end())
            return res;
        if(beginWord == endWord)
            return res;
        queue<pair<string, vector<string>>> q;
        // vector<string> temp;
        q.push({beginWord, {beginWord}});
        // int t = 1;
        while(!q.empty())
        {
            int n = q.size();
            unordered_set<string> to_be_deleted;
            while(n--)
            {
                string word = (q.front()).first;
                vector<string> v = (q.front()).second;
                q.pop();
                for(int i = 0; i < word.size(); i++)
                {
                    char k = word[i];
                    for(char j = 'a'; j <= 'z'; j++)
                    {
                        if(j == k)
                            continue;
                        word[i] = j;
                        // vector<string>
                        if(dict.find(word) != dict.end())
                        {
                            vector<string> g = v;
                            g.push_back(word);
                            to_be_deleted.insert(word);
                            if(word == endWord)
                                res.push_back(g);
                                // return t + 1;
                            q.push({word, g});
                            // q.push(word);
                            // auto itr = dict.find(word);
                            // dict.erase(itr);
                        }
                    }
                    word[i] = k;
                    
                }
            }
            for(auto it = to_be_deleted.begin(); it != to_be_deleted.end(); it++)
            {
                auto itr = dict.find(*it);
                dict.erase(itr);
            }
            if(res.size() > 0)
                return res;
            // t++;
        }
        return res;
    }
};