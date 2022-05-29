class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> val(n);
        for(int i =0; i < n; i++)
        {
            int t = 0;
            for(auto c : words[i])
                t |= (1 << (c-'a'));
            val[i] = t;
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if((val[i] & val[j]) == 0)
                {
                    ans = max(ans, (int)words[i].size() * (int)words[j].size());
                }
            }
        }
        return ans;
    }
};