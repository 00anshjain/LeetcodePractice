class Solution {
public:
    typedef long long ll;
    long long maximumSubsequenceCount(string text, string pattern) {
        int n = text.size();
        ll ans = 0;
        ll mx = 0;
        vector<ll> arr(n);
        ll x = 0;
        if(pattern[0] == pattern[1])
            x = -1;
        ll second = 0, first = 0;
        for(ll i = 0; i < n; i++)
        {
            if(text[i] == pattern[0])
            {
                x++;
                first++;
            }
            arr[i] = x;
            if(text[i] == pattern[1])
            {
                second++;
                // mx = max(mx, arr[i]);
                ans += arr[i];
            }
        }
        // for(int i = 0; i < n; i++)
        //     cout<<arr[i]<<" ";
        // cout<<endl;
        // if(ans == 0)
        return ans + max(first, second);
        
        
        
        
        
        
        
        
    }
};