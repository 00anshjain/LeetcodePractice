class Solution {
public:
    unordered_map<string, int> emailToUid;
    unordered_map<int, int> par;
    unordered_map<int, string> UidToName, UidToEmail;
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
        for(auto v : accounts)
        {
            int n = v.size();
            string name = v[0];
            for(int i = 1; i < n; i++)
            {
                if(emailToUid.find(v[i]) == emailToUid.end())
                {
                    
                    emailToUid[v[i]] = ++uid;
                    UidToEmail[uid] = v[i];
                    UidToName[uid] = name;
                    par[uid] = uid;
                    
                }
                int p1 = emailToUid[v[1]];
                int p2 = emailToUid[v[i]];
                getUnion(p1, p2);
            }
        }
        // cout<<uid<<endl;
        unordered_map<int, vector<int>> mp;
        for(int i = 1; i <= uid; i++)
        {
            int p = findPar(i);
            mp[p].push_back(i);
        }
        // cout<<mp.size();
        vector<vector<string>> ans;
        for(auto x : mp)
        {
            
            vector<string> arr;
            arr.push_back("");
            for(auto v : x.second)
                arr.push_back(UidToEmail[v]);
            sort(arr.begin(), arr.end());
            arr[0] = UidToName[x.first];
            ans.push_back(arr);
        }
        return ans;
            
    }
};