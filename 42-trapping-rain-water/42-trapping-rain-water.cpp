class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int lmax[n], rmax[n];
        lmax[0] = 0;
        rmax[n-1] = 0;
        for(int i = 1; i < n; i++)
        {
            lmax[i] = max(arr[i-1], lmax[i-1]);
        }
        for(int i = n-2; i >=0; i--)
        {
            rmax[i] = max(arr[i+1], rmax[i+1]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(lmax[i] > arr[i] && rmax[i] >arr[i])
            {
                ans += (min(lmax[i], rmax[i]) - arr[i]);
            }
        }
        return ans;
    }
};