class Solution {
public:
    int findPar(vector<int> &par, int p)
    {
        if(par[p] == p)
            return p;
        return par[p] = findPar(par, par[p]);
    }
    bool unionPar(vector<int>& par, int a, int b)
    {
        int p1 = findPar(par, a);
        int p2 = findPar(par, b);
        if(p1 == p2)
            return false;
        par[p1] = p2;
        return true;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> arr(n+1, -1);
        int e1 = -1, e2 = -1;
        for(int i = 0; i < n; i++)
        {
            auto x = edges[i];
            if(arr[x[1]] != -1)
            {
                e1 = arr[x[1]];
                e2 = i;
                break;
            }
            else
                arr[x[1]] = i;
        }
        vector<int> par(n+1, -1);
        for(int i = 1; i <= n; i++)
            par[i]  = i;
        for(int i = 0; i < n; i++)
        {
            if(i == e2)
                continue;
            if(!unionPar(par, edges[i][0], edges[i][1]))
            {
                if(e1 != -1)
                    return edges[e1];
                return edges[i];
            }
        }
        return edges[e2];
        
    }
};