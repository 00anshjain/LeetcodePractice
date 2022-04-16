class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
//         unordered_map<int, int> mp;
//         int mx = 0;
//         int n = arr.size();
        int n = arr.size();
        unordered_map<int,int> mp;
        int ans = -1;
        for(int i = 0; i < n; i++)
        {
            if(mp[arr[i] - d] == 0)
                mp[arr[i]] = 1;
            else
                mp[arr[i]] = 1 + mp[arr[i] - d];
            ans = max(ans,mp[arr[i]]);
//             if(difference == 0)
//             {
//                 mp[arr[i]]++;
//                 mx = max(mx, mp[arr[i]]);
//                 continue;
//             }
//             if(mp.find(arr[i]) == mp.end())
//                 mp[arr[i]] = 1;
//             // int k = mp[arr[i]];
//             if(mp.find(arr[i] - difference) != mp.end())
//             {
//                 mp[arr[i]] = max(mp[arr[i]], mp[arr[i] - difference] + 1);
//             }
//             // if(mp.find(arr[i] + difference) != mp.end())
//             // {
//             //     mp[arr[i]] = max(mp[arr[i]], mp[arr[i] + 1] + 1);
//             // }
//             mx = max(mp[arr[i]], mx);
            
        }
        return ans;
        // return mx;
        
    }
};