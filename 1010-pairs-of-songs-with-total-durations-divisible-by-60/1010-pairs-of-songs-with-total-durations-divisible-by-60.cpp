class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& t) {
        vector<int> temp(60, 0);
        int ans = 0;
        for(auto x : t)
        {
            int p = (x%60);
            ans += temp[(60 - p)%60]; 
            temp[p]++;
        }
        return ans;
        
    }
};