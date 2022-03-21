class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> mp; // map store character starting and ending poition
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            if(mp.find(s[i]) == mp.end())
                mp[s[i]] = {i, i};
            else
                mp[s[i]].second = i;
        }
        int i = 0;
        vector<int> ans;
        while(i < n)
        {
            int j = mp[s[i]].second;
            int cnt = 0;
            while(i <= j)
            {
                j = max(j, mp[s[i]].second);
                cnt++;
                i++;
            }
            // cout<<s[i]i<<endl;
            // if(j == n)
            //     cnt++;
            ans.push_back(cnt);
            // count++;
            // i++;
        }
        return ans;
        
    }
};