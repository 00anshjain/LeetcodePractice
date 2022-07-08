class SummaryRanges {
public:
    map<int, int> par, sz;
    int findPar(int i)
    {
        if(par[i] == i)
            return i;
        return par[i] = findPar(par[i]);
    }
    SummaryRanges() {
        //Aur kya haal chal
    }
    
    void addNum(int val) {
        if(par.find(val) == par.end())
        {
            par[val] = val;
            sz[val] = 1;
            if(par.find(val+1) != par.end())
            {
                par[val+1] = val;
                sz[val] = sz[val+1]+1;
            }
            if(par.find(val-1) != par.end())
            {
                int p = findPar(val-1);
                sz[p] += sz[val];
                par[val] = p;
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for(auto x : par)
        {
            if(x.first == x.second) //par[i] = i;
            {
                ans.push_back({x.first, x.first + sz[x.first] - 1});
            }
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */