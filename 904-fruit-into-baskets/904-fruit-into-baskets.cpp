class Solution {
public:
    int totalFruit(vector<int>& arr) {
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        int unq = 0;
        int cnt = 0, ans = 0;
        int n = arr.size();
        for(auto x : arr)
        {
            if(mp[x] == 0)
            {
                while(unq > 1)
                {
                    mp[arr[i]]--;
                    // i++;
                    if(mp[arr[i]] == 0)
                        unq -= 1;
                    i++;
                    cnt -= 1 ;
                }
                unq += 1;
            }
            mp[x]++;
            cnt+= 1;
            ans = max(ans, cnt);
        }
        return ans;
    }
};