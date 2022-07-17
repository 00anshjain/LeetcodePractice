class Solution {
public:
    // [1, 10, 20]  =>5       , 5
    typedef long long ll;
    ll n;
    bool possible(ll t, vector<int> &time, ll total)
    {
        for(ll i = 0; i < n; i++)
        {
            total -= (t/time[i]);
            if(total <= 0)
                return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        n = time.size();
        ll left = 0;
        ll right = ((ll)*max_element(time.begin(), time.end()))*(totalTrips);
        ll ans = -1;
        while(left <= right)
        {
            ll mid = (left + right)/2;
            if(possible(mid, time, totalTrips))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};