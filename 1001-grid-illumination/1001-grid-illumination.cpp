class Solution {
public:
    unordered_map<int, int> r, c, diag1, diag2;
    int rdir[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};
    int cdir[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
    int N;
    bool isSafe(int i, int j)
    {
        if(i < 0 || j < 0 || i >= N || j >= N)
            return false;
        return true;
    }
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        N = n;
        map<pair<int, int>, bool> mp; // for currently on
        for(auto x : lamps)
        {
            if(mp.find({x[0], x[1]}) != mp.end())
                continue;
            mp[{x[0], x[1]}] = true;
            r[x[0]]++;
            c[x[1]]++;
            diag1[x[1] + x[0]]++;
            diag2[x[1] - x[0]]++;
        }
        vector<int> ans;
        for(auto x : queries)
        {
            if(r[x[0]] > 0|| c[x[1]] > 0 || diag1[x[1] + x[0]] > 0 || diag2[x[1] - x[0]] > 0)
                ans.push_back(1);
            else
                ans.push_back(0);
            for(int i = 0;  i < 9; i++)
            {
                int p = x[0] + rdir[i];
                int q = x[1] + cdir[i];
                if(mp.find({p, q}) == mp.end())
                    continue;
                if(isSafe(p, q) && (mp[{p, q}] == true))
                {
                    mp[{p, q}] = false;
                    r[p]--;
                    c[q]--;
                    diag1[p+q]--;
                    diag2[q-p]--;
                }
            }
        }
        return ans;
        
        
        
    }
};