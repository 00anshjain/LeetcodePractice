class Solution {
public:
    vector<int> par;
    int findPar(int i)
    {
        if(par[i] == i)
            return i;
        return par[i] = findPar(par[i]);
    }
    void getUnion(int i, int j)
    {
        int p = findPar(i);
        int q = findPar(j);
        if(p != q)
            par[p] = q;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int uid = 0;
        int sz = accounts.size();
        par.resize(sz);
        unordered_map<string, int> emailToParent;
        for(int i = 0; i < sz; i++)
            par[i] = i;
        for(int j = 0; j < sz; j++)
        {
            vector<string> v = accounts[j];
            int n = v.size();
            string name = v[0];
            for(int i = 1; i < n; i++)
            {
                if(emailToParent.find(v[i]) == emailToParent.end())
                {
                    emailToParent[v[i]] = j;
                    // emailToParent.insert(make_pair({v[i], j}));
                }
                // else
                // {
                    int p1 = emailToParent[v[i]];
                    int p2 = emailToParent[v[1]];
                    getUnion(p1, p2);
                // }
            }
        }
        // cout<<uid<<endl;
        unordered_map<int, vector<string>> mp;
        for(auto x : emailToParent)
        {
            int p = findPar(x.second);
            mp[p].push_back(x.first);
        }
        // cout<<mp.size();
        vector<vector<string>> ans;
        for(auto x : mp)
        {
            
            vector<string> arr;
            arr.push_back(accounts[x.first][0]);
            sort(x.second.begin(), x.second.end());
            for(auto y : x.second)
            {
                arr.push_back(y);
            }
            // arr.push_back(x.second);
            // arr.push_back("");
            // for(auto v : x.second)
            //     arr.push_back(UidToEmail[v]);
            // sort(arr.begin(), arr.end());
            // arr[0] = UidToName[x.first];
            ans.push_back(arr);
        }
        return ans;
            
    }
};