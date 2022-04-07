class Solution {
public:
    typedef long long ll;
    int maximumCandies(vector<int>& candies, long long k) {
        ll left = 0;
        ll right = *max_element(candies.begin(), candies.end());
        ll ans = 0;
        while(left <= right)
        {
            ll mid = (left + right)/2;
            if(mid==0)
            {
                ans = 0;
                left = mid+1;
                continue;
            }
            ll bacche = 0;
            for(auto x : candies)
            {
                
                bacche += (x/mid);
                // while(x >= mid)
                // {
                //     bacche++;
                //     x -= mid;
                //     if(bacche >= k)
                //     break;
                // }
                if(bacche >= k)
                    break;
            }
            if(bacche >= k)
            {
                // break;
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
            // cout<<ans<<"  "<<left<<"  "<<right<<endl;
        }
        return ans;
        
    }
};