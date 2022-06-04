class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastidx;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            lastidx[s[i]] = i;
        }
        int j = 0, last = 0;
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            last = max(last, lastidx[s[i]]);
            if(last == i)
            {
                ans.push_back(i-j+1);
                j = i+1;
            }
        }
        return ans;
        
    }
};