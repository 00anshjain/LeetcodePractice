class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxx = 0, mask = 0;
        for(int i = 30; i >= 0; i--)
        {
            mask |= (1<<i);
            unordered_set<int> st;
            for(auto x : nums)
                st.insert(x & mask);
            
            int newMax = maxx | (1<<i);
            for(auto x: st)
            {
                if(st.find(x ^ newMax) != st.end())
                {
                    maxx = newMax;
                    break;
                }
            }
        }
        return maxx;
    }
};