class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string, string>> letterlog; //string - identifier, identifier
        vector<string> diglog;
        
        for(auto s : logs)
        {
            int n = s.size();
            int i = 0;
            for(i = 0; i < n; i++)
            {
                if(s[i] == ' ')
                    break;
            }
            if(s[i+1] >= '0' && s[i+1] <= '9')
                diglog.push_back(s);
            else
                letterlog.push_back({s.substr(i+1, n-1 - (i+1) + 1) ,s});
                // letterlog[s.substr(i+1, n-1 - (i+1) + 1)] = s.substr(0, i+1);
        }
        sort(letterlog.begin(), letterlog.end());
        vector<string> ans;
        for(auto s : letterlog)
            ans.push_back(s.second);
        for(auto s : diglog)
            ans.push_back(s);
        return ans;
    }
};