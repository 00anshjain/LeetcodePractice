class Solution {
public:
    int n;
    vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    void recur(string &digits, int i, vector<string> &ans, string &curr)
    {
        if(i == n)
        {
            ans.push_back(curr);
            return;
        }
        int k = (digits[i] - '0');
        for(auto c : pad[k])
        {
            curr.push_back(c);
            recur(digits, i+1, ans, curr);
            curr.pop_back();
        }
        
        
    }
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        // cout<<n;
        vector<string> ans;
        if(n == 0)
            return ans;
        string curr = "";
        recur(digits, 0, ans, curr);
        return ans;
    }
};