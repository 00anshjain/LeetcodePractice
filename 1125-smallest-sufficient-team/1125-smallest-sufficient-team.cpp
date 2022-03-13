class Solution {
public:
    const int INF = 1e9 + 7;
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        map<string, int> mp;
        int n = req_skills.size();
        int m = people.size();
        for(int i = 0 ; i<n; i++)
            mp[req_skills[i]] = i;
        vector<int> skills(m,0);
        for(int i = 0; i<m; i++)
        {
            for(string x : people[i])
            {   
                skills[i] |= (1 << mp[x]);
            }
        }
        int k = (1<<n);
        vector<pair<int, vector<int>>> dp(1<<n, {INF, {}});
        dp[0].first = 0;
        for(int i = 0; i < m; i++)
        {
            for(int mask = 0; mask < k; mask++)
            {
                int newMask = (mask | skills[i]);
                if(dp[newMask].first > dp[mask].first + 1)
                {
                    dp[newMask].first = dp[mask].first + 1;
                    dp[newMask].second = dp[mask].second;
                    dp[newMask].second.push_back(i);
                }
            }
        }
        return dp[k-1].second;
    }
};