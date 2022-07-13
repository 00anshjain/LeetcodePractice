class Solution {
public:
    int xdir[8] = {1, 1, 1, 0, 0, -1, -1, -1};
    int ydir[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    void check(set<pair<int, int>> &st, int x, int y, vector<vector<int>>& res, int dir)
    {
        if(x<0 || y < 0 || x >= 8 || y >= 8)
            return;
        pair<int, int> p = {x, y};
        if(st.find(p) != st.end())
        {
            res.push_back({x, y});
            return;
        }
        check(st, x + xdir[dir], y + ydir[dir], res, dir);
        
    }
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> res;
        set<pair<int, int>> st;
        for(auto x : queens)
            st.insert({x[0], x[1]});
        for(int i = 0; i < 8; i++)
        {
            check(st, king[0] + xdir[i], king[1] + ydir[i], res, i);
        }
        return res;
    }
};