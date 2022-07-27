class Solution {
public:
    // typedef long long mask = 0;
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int n = words.size();
        // vector<int> wordmask;
        unordered_map<int, unordered_map<int, int>> startLetter;
        int j = 0;
        for(auto x: words)
        {
            int mask = 0;
            for(auto c : x)
            {
                // startLetter[c-'a'].insert(j);
                mask |= (1<<(c-'a'));
            }
            int taken = 0;
            for(auto c : x)
            {
                if((taken & (1<<(c-'a'))) > 0)
                    continue;
                startLetter[c-'a'][mask]++;
                taken |= 1<<(c-'a');
            }
            // wordmask.push_back(mask);
            // j++;
        }
        vector<int> ans;
        for(auto x : puzzles)
        {
            int mask = 0;
            for(auto c : x)
            {
                mask |= (1<<(c-'a'));
            }
            int cnt = 0;
            for(auto mp : startLetter[x[0] - 'a'])
            {
                int m = mp.first;
                // for(auto i : st)
                // {
                if((m | mask) == mask)
                {
                    cnt += mp.second;
                }
                // }
            }
            // for(int i = 0; i < n; i++)
            // {
            //     if((wordmask[i] & (1<<(x[0]-'a'))) == 0)
            //         continue;
            //     if((wordmask[i] | mask) == mask)
            //     {
            //         cnt++;
            //     }
            // }
            ans.push_back(cnt);
        }
        return ans;
    }
};