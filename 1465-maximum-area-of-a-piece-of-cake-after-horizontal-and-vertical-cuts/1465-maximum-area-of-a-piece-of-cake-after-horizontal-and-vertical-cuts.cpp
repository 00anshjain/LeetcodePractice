class Solution {
public:
    int mod = 1e9+7;
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        hc.push_back(h);
        vc.push_back(w);
        int lastH = 0, lastV = 0;
        int mxH = 0, mxV = 0;
        for(auto x : hc)
        {
            mxH = max(mxH, x - lastH);
            lastH = x;
        }
        for(auto x : vc)
        {
            mxV = max(mxV, x - lastV);
            lastV = x;
        }
        long long ans = (((long long)mxV) * mxH);
        return (ans % mod);
    }
};