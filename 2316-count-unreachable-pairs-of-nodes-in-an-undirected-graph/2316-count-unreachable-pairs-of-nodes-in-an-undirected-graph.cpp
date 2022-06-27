class Solution {
public:
    typedef long long ll;
    vector<int> parent, sz;
    int findParent(int a)
    {
        if(parent[a] == a)
            return a;
        return parent[a] = findParent(parent[a]);
    }
    void unionSet(int a, int b)
    {
        int p1 = findParent(a);
        int p2 = findParent(b);
        if(p1 != p2)
        {
            if(sz[p1] >= sz[p2])
            {
                parent[p2] = p1;
                sz[p1] += sz[p2];
            }
            else
            {
                parent[p1] = p2;
                sz[p2] += sz[p1];
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        sz.resize(n, 1);
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
        for(auto x : edges)
        {
            unionSet(x[0], x[1]);
        }
        unordered_set<int> st;
        for(int i = 0; i < n; i++)
        {
            st.insert(findParent(i));
        }
        ll siz = 0l;
        ll ans = 0l;
        for(auto x : st)
        {
            ans += siz*sz[x];
            siz += sz[x];
        }
        return ans;
        
    }
};