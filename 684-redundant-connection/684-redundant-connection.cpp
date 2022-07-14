class Solution {
public:
    vector<int> par, sz;
    int findPar(int a)
    {
        if(par[a] == a)
            return a;
        return par[a] = findPar(par[a]);
    }
    void unionSet(int p1, int p2)
    {
        if(sz[p2] > sz[p2])
        {
            par[p1] = p2;
            sz[p2] += sz[p1]; 
        }
        else
        {
            par[p2] = p1;
            sz[p1] += p2;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        par.resize(n+1);
        sz.resize(n+1);
        for(int i = 1; i <= n; i++)
        {
            par[i] = i;
            sz[i] = 1;
        }
        vector<int> ans;
        for(auto x : edges)
        {
            int p1 = findPar(x[0]);
            int p2 = findPar(x[1]);
            if(p1 == p2)
                return x;
            unionSet(p1, p2);
        }
        return ans;
    }
};