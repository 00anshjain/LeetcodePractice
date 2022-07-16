// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        vector<pair<int, int>> v;
        int mx = 0, mn = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            // if(arr[i]- k >= 0)
                v.push_back({arr[i] - k, i});
            v.push_back({arr[i] + k, i});
            mx = max(mx, arr[i]);
            mn = min(mn, arr[i]);
        }
        int ans = mx - mn;
        int ele = 0, left = 0, right = 0;
        int sz = v.size();
        sort(v.begin(), v.end());
        vector<int> visited(n, 0);
        while(ele < n && right < sz)
        {
            if(visited[v[right].second] == 0)
                ele++;
            visited[v[right].second]++;
            right++;
        }
        if(ele == n)
        {
            ans = min(ans, v[right-1].first - v[left].first);
        }
        while(right < sz)
        {
            if(visited[v[left].second] == 1)
                ele--;
            visited[v[left].second]--;
            left++;
            while(ele < n && right < sz)
            {
                if(visited[v[right].second] == 0)
                    ele++;
                visited[v[right].second]++;
                right++;
            }
            if(ele == n)
                ans = min(ans, v[right-1].first - v[left].first);
        }
        return ans;
        // code here
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends