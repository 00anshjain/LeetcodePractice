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
        // par[p2] = p1;
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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        par.resize(n+1);
        sz.resize(n+1);
        for(int i = 1; i <= n; i++)
        {
            par[i] = i;
            sz[i] = 1;
        }
        vector<int> arr(n+1, -1);
        int black1 = -1, black2 = -1;//for two parents of a node, we blacklistr both the edges
        for(int i = 0; i < n; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            if(arr[v] != -1)
            {
                black1 = i; //we store index of edge that is creating problem
                black2 = arr[v];
                break;
            }
            arr[v] = i;
        }
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            vector<int> x = edges[i];
            if(i == black1)
                continue; 
            //that we check if cycle exist after removing black1 also, then black2 is responsible for it
            //so we remove black2 then
            //else remove black1
            //ok if black1 == -1, means no node with two parents, then remove edge which lead to form cycle
            int p1 = findPar(x[0]);
            int p2 = findPar(x[1]);
            if(p1 == p2)
            {
                //cycle occured even after removing black1
                //if black1 == -1, no edge leading to two parent of a node
                if(black2 == -1)
                    return x;
                return edges[black2];
            }
            unionSet(p1, p2);
        }
        return edges[black1];
        // return ans;
    }
};