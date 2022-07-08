class Solution {
public:
    unordered_map<int, int> par;
    unordered_map<int, int> sz;
    int findPar(int u)
    {
        if(par[u] != u)
            par[u] = findPar(par[u]);
        return par[u];
    }
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        for(auto x : nums)
        {
            if(par.find(x) == par.end())
            {
                par[x] = x;
                sz[x] = 1;
                ans = max(ans, 1);
            
                if(par.find(x+1) != par.end())
                {
                    int p = findPar(x+1);
                    if(p != x+1)
                        continue;
                    sz[x] = sz[x+1]+1;
                    par[x+1] = x;
                    ans = max(ans, sz[x]);
                }
                if(par.find(x-1) != par.end())
                {
                    int p = findPar(x-1);
                    sz[p] += sz[x];
                    par[x] = p;
                    ans = max(ans, sz[p]);
                }
            }
            
        }
        return ans;
        
    }
};