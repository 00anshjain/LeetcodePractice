class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& pref, vector<vector<int>>& pairs) {
        // unordered_set<int> ans;
        int unhappy = 0;
        vector<bool> visited(n);
        unordered_map<int, int> pr;
        for(auto x : pairs)
        {
            pr[x[0]] = x[1];
            pr[x[1]] = x[0];
        }
        for(auto V : pairs)
        {
            int v = V[1];
            int u = V[0];
            if(!visited[u])
            {
                for(auto x : pref[u])
                {
                    if(x == v)
                        break;
                    bool flag = false;
                    int y = pr[x];
                    for(auto z : pref[x])
                    {
                        if(z == y)
                            break;
                        if(z == u)
                        {
                            unhappy++;
                            // ans.insert(z);
                            // ans.insert(u);
                            flag = true;
                            break;
                        }
                    }
                    if(flag)
                        break;
                }
                visited[u] = true;
            }
            
            if(!visited[v])
            {
                for(auto x : pref[v])
                {
                    if(x == u)
                        break;
                    bool flag = false;
                    int y = pr[x];
                    for(auto z : pref[x])
                    {
                        if(z == y)
                            break;
                        if(z == v)
                        {
                            unhappy++;
                            // ans.insert(z);
                            // ans.insert(u);
                            flag = true;
                            break;
                        }
                    }
                    if(flag)
                        break;
                }
                visited[v] = true;
            }            
            
            
            
        }
        return unhappy;
    }
};