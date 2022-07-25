class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = strs[0];
        for(int i = 1; i < n; i++)
        {
            int j = 0;
            while(j < ans.size() && j < strs[i].size())
            {
                if(ans[j] != strs[i][j])
                {
                    ans = ans.substr(0, j);
                    break;
                }
                j++;
            }
            if(j == strs[i].size() && j < ans.size())
                ans = strs[i];
        }
        return ans;
    }
};