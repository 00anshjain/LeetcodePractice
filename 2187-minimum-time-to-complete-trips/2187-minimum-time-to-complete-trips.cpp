class Solution {
public:
    typedef long long ll;
    bool check(ll mid, ll total, vector<int>& time)
    {
        ll t = 0;
        for(auto x : time)
        {
            t += (mid/x);
            if(t >= total)
                return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int total) {
        ll right = *min_element(time.begin(), time.end()) * (ll)total;
        ll left = 0;
        ll ans = right;
        while( left <= right)
        {
            ll mid = (left + right)/2;
            // cout<<mid<<endl;
            if(check(mid, total, time))
            {
                // cout<<"idhar"<<endl;
                right = mid - 1;
                ans = mid;
            }
            else
            {
                left = mid+1;
            }
        }
        return ans;
    }
};