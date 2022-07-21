class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0, c = 0;
        for(auto x : timeSeries)
        {
            if(x >= c)
                ans += duration;
            else//
            {
                ans += x+duration - c;
            }
            c = x + duration;
        }
        return ans;
    }
};