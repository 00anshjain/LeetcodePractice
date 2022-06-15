class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& pref, vector<vector<int>>& pairs) {
        unordered_set<int> ans;
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
            
            for(auto x : pref[u])
            {
                if(x == v)
                    break;
                // bool flag = false;
                for(auto z : pref[x])
                {
                    if(z == pr[x])
                        break;
                    if(z == u)
                    {
                        ans.insert(z);
                        ans.insert(u);
                        // flag = true;
                        break;
                    }
                }
                // if(flag)
                //     break;
                
            }
            
            for(auto x : pref[v])
            {
                if(x == u)
                    break;
                // bool flag = false;
                for(auto z : pref[x])
                {
                    if(z == pr[x])
                        break;
                    if(z == v)
                    {
                        ans.insert(z);
                        ans.insert(v);
                        // flag = true;
                        break;
                    }
                }
                // if(flag)
                //     break;
                
            }
            
            
            
            
        }
        return ans.size();
    }
};