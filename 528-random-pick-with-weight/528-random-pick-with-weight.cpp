class Solution {
public:
    vector<int> pre;
    int mx, n;
    Solution(vector<int>& w) {
        n = w.size();
        pre.resize(n);
        pre[0] = w[0];
        for(int i = 1; i < n; i++)
        {
            pre[i] = pre[i-1] + w[i];
        }
        mx = pre[n-1];
    }
    int pickIndex() {
        int k = (rand()%mx)+1;
        return lower_bound(pre.begin(), pre.end(), k) - pre.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */