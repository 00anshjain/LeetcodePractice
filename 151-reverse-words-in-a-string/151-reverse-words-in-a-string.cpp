class Solution {
public:
    string reverseWords(string S) {
        string ans = "";
        int n = S.size();
        int i = n-1;
        while(i >= 0)
        {
            if(S[i] == ' ')
            {
                i--;
                continue;
            }
            int j = i;
            // if(j != n-1)
            //     ans += ' ';
            while(j >= 0 && S[j] != ' ')
                j--;
            ans += S.substr(j+1, i - j);
            i = j-1;
            // if(j > 0)
            ans += ' ';
        }
        while(ans.size() > 0 && ans.back() == ' ')
            ans.pop_back();
        return ans;
    }
};