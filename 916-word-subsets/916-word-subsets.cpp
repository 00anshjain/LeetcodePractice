class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> f;
        for(auto w : words2)
        {
            unordered_map<char, int> mp;
            for(auto c : w)
            {
                mp[c]++;
            }
            for(auto x : mp)
            {
                f[x.first] = max(f[x.first], x.second);
            }
            // f.push_back(mp);
        }
        vector<string> ans;
        for(auto w : words1)
        {
            unordered_map<char, int> mp;
            for(auto c : w)
                mp[c]++;
            bool flag = false;
            for(auto x : f)
            {
                if(mp[x.first] < x.second)
                {
                    flag = true;
                    break;
                }
            }   
            if(!flag)
                ans.push_back(w);
            
//             for(auto freqmap : f)
//             {
//                 for(auto x : freqmap)
//                 {
//                     if(x.second > mp[x.first])
//                     {
//                         flag = true;
//                         break;
//                     }
//                 }
//                 if(flag)
//                     break;
//             }
        }
        return ans;
    }
};