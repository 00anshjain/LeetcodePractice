class Solution {
public:
    unordered_map<string, int> skillNo;
    int K;
    int ans = INT_MAX;
    vector<int> ans_vec;
    void recur(vector<int>& skillmask, int n, int mask, int cnt, vector<int> &vec, vector<int>& dp)
    {
        if(n == 0)
        {
            if(mask == (1<<K) - 1 && cnt < ans)
            {
                ans = cnt;
                ans_vec = vec;
            }
            return;
        }
        if(dp[mask] < cnt)
            return;
        dp[mask] = cnt;
        recur(skillmask, n-1, mask, cnt, vec, dp);
        vec.push_back(n-1);
        recur(skillmask, n-1, mask | skillmask[n-1], cnt + 1, vec, dp);
        vec.pop_back();
        
        
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int cnt = 0;
        for(auto x : req_skills)
            skillNo[x] = cnt++;
        K = req_skills.size();
        vector<int> dp(1<<K, INT_MAX);
        vector<int> skillmask;
        for(auto x: people)
        {
            int num = 0;
            for(auto y : x)
            {
                // if(skillNo.find(y) == skillNo.end())
                //     continue;
                num |= (1<<skillNo[y]);
            }
            skillmask.push_back(num);
        }
        int curr = 0, c = 0;
        vector<int> v;
        recur(skillmask, people.size(), curr, c, v, dp);
        return ans_vec;
    }
};