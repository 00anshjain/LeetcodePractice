class Solution {
public:
    int findParent(vector<int> &par, int i)
    {
        if(par[i] == i)
            return i;
        return par[i] = findParent(par, par[i]);        
    }
    void getUnion(int i, int j, vector<int> &par, vector<int> &sz)
    {
        int p1 = findParent(par, i);
        int p2 = findParent(par, j);
        if(p1 != p2)
        {
            if(sz[p1] > sz[p2])
            {
                par[p2] = p1;
                sz[p1] += sz[p2];
            }
            else
            {
                par[p1] = p2;
                sz[p2] += sz[p1];
            }   
        }
    }
    int findCircleNum(vector<vector<int>>& con) {
        int n = con.size();
        vector<int> par(n+1), sz(n+1);
        for(int i = 1; i <= n; i++)
        {
            par[i] = i;
            sz[i] = i;
        }
        for(int i = 0; i< n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    continue;
                if(!con[i][j])
                    continue;
                getUnion(i+1, j+1, par, sz);
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(par[i] == i)
                ans++;
        }
        return ans;
    }
};