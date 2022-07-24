class Solution {
public:
    typedef long long ll;
    int getCount(int n)
    {
        int cnt = 0;
        while(n > 0)
        {
            int rmsb = n & -n;
            cnt++;
            n -= rmsb;
        }
        return cnt;
    }
    // int binarySearch(int l, int r, setCount, k - r)
    long long countExcellentPairs(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        vector<int> setCount;
        for(auto c : st)
        {
            // mp[nums[i]]++;
            // if(mp[nums[i]] == 1)
            setCount.push_back(getCount(c));
        }
        sort(setCount.begin(), setCount.end());
        ll ans = 0l;
        for(auto r : setCount)
        {
            // int r = setCount[i];
            ans += (setCount.end() - lower_bound(setCount.begin(), setCount.end(), k-r));
        }
        return ans;
    }
};