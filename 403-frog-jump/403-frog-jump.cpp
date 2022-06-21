class Solution {
public:
    unordered_map<int, set<int>> mp;
    bool canCross(vector<int>& stones) {
        set<int> st;
        for(auto s : stones)
            mp[s] = st;
        mp[0].insert(1);
        int n = stones.size();
        for(int i = 0; i < n; i++)
        {
            int curr = stones[i];
            for(auto jump : mp[curr])
            {
                if(mp.find(jump + curr) != mp.end())
                {
                    int newPos = jump+curr;
                    if(newPos == stones[n-1])
                        return true;
                    if(jump -1 > 0)
                        mp[newPos].insert(jump - 1);
                    mp[newPos].insert(jump + 1);
                    mp[newPos].insert(jump);
                }
            }
        }
        return false;
    }
};