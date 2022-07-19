class Solution {
public:
    unordered_map<int, int> mp;
    unordered_set<int> s;
    int validNums = 0;
    Solution(int n, vector<int>& black) {
        unordered_set<int> st(black.begin(), black.end());
        s = st;
        // unordered_map<int, int> mp;
        validNums = n - st.size();
        int i = validNums;
        for(auto &x:st)
        {
            if(x<validNums)
            {
                while(st.count(i)) i++; 
				mp[x] = i++;
            }      
        } 
    }
    
    int pick() {
        int k = rand()%validNums;
        if(mp.find(k) != mp.end())
            return mp[k];
        return k;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */