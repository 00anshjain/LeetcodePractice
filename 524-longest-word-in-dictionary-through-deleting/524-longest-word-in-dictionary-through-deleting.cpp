class Solution {
public:
    static bool comp(string &s1, string &s2)
    {
        if(s1.size() == s2.size())
            return s1 < s2;
        return s1.size() > s2.size();
    }
    string findLongestWord(string s, vector<string>& dict) {
        sort(dict.begin(), dict.end(), comp);
        for(auto x : dict)
        {
            int n = s.size();
            int m = x.size();
            int i = 0, j = 0;
            while(i < n && j < m)
            {
                if(s[i] == x[j])
                    j++;
                i++;
            }
            if(j == m)
                return x;
        }
        return "";
    }
};