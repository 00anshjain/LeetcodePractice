class Solution {
public:
    int findUnsortedSubarray(vector<int>& arr) {
        int n = arr.size();
        int l = 0;
        while(l+1 < n && arr[l+1] >= arr[l])
            l++;
        if(l == n-1)
            return 0;
        int r = n-1;
        while(r-1 >= 0 && arr[r-1] <= arr[r])
            r--;
        // if(l >= r)
        //     return 0;
        // cout<<l<<" "<<r<<endl;
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(int i = l; i <= r; i++)
        {
            mn = min(mn, arr[i]);
            mx = max(mx, arr[i]);
        }
        for(int i = 0; i < l; i++)
        {
            if(arr[i] > mn)
            {
                l = i;
                break;
            }
        }
        for(int i = n-1; i > r; i--)
        {
            if(arr[i] < mx)
            {
                r = i;
                break;
            }
        }
        // cout<<l<<" "<<r<<endl;
        return r - l + 1;
    }
};