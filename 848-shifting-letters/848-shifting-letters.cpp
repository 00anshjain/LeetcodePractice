class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int curr = 0;
        int n = s.size();
        // typedef long long ll;
        for(int i = n-1; i >= 0; i--)
        {
            curr += shifts[i];
            curr %= 26;
            int p = s[i] - 'a' + curr;
            p = p%26;
            s[i] = char(p+'a');
        }
        return s;
    }
};