class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int mx = 0;
        int cnt = 0;
        unordered_map<char, int> mp;
        for(auto x : tasks)
        {
            mp[x]++;
            if(mp[x] > mx)
            {
                mx = mp[x];
                cnt = 1;
            }
            else if(mp[x] == mx)
                cnt++;
        }
        // cout<<cnt<<" "<<mx<<endl;
        return max((int)tasks.size(), (mx-1)*(n+1) + cnt);
    }
};