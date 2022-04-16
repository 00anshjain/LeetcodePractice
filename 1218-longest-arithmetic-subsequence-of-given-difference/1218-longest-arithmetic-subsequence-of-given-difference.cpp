class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> mp;
        int mx = 0;
        int n = arr.size();
        
        for(int i = 0; i < n; i++)
        {
            if(difference == 0)
            {
                mp[arr[i]]++;
                mx = max(mx, mp[arr[i]]);
                continue;
            }
            if(mp.find(arr[i]) == mp.end())
                mp[arr[i]] = 1;
            // int k = mp[arr[i]];
            if(mp.find(arr[i] - difference) != mp.end())
            {
                mp[arr[i]] = max(mp[arr[i]], mp[arr[i] - difference] + 1);
            }
            // if(mp.find(arr[i] + difference) != mp.end())
            // {
            //     mp[arr[i]] = max(mp[arr[i]], mp[arr[i] + 1] + 1);
            // }
            mx = max(mp[arr[i]], mx);
            
        }
        return mx;
        
    }
};