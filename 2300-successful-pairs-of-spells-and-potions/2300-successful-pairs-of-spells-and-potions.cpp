class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        int m = potions.size();
        int n = spells.size();
        for(int i = 0; i < n; i++)
        {
            int l = 0, r = m-1;
            int k = m;
            while(l <= r)
            {
                int mid = l + (r-l)/2;
                if((long long)potions[mid] * (long long)spells[i] >= success)
                {
                    k = mid;
                    r = mid-1;
                }
                else
                    l = mid + 1;
            }
            // if(k == -1)
            //     ans.push_back(0);
            // else
            ans.push_back(m - k);
        }
        return ans;
    }
};