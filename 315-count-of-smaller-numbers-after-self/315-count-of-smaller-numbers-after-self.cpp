class Solution {
public:
    void merge(vector<pair<int, int>> &nums, vector<int> &cnt, int l, int m, int r, vector<pair<int, int>>& temp)
    {
        int i = l, j = m+1, k = l;
        int curr = 0;
        // vector<pair<int, int>> temp(r+1);
        while(i <= m && j <= r)
        {
            if(nums[i].first > nums[j].first)
            {
                temp[k++] = nums[j];
                curr++;
                // cnt[nums[j].second] += curr;
                j++;
            }
            else// if(nums[i].first < nums[j].first)
            {
                temp[k++] = nums[i];
                cnt[nums[i].second] += curr;
                i++;
            }
        }
        while(i <= m)
        {
            temp[k++] = nums[i];
            cnt[nums[i].second] += curr;
            i++;
        }
        while(j <= r)
        {
            temp[k++] = nums[j];
            // cnt++;
            // cnt[nums[j].second] += curr;
            j++;
        }
        for(int i = l; i <= r; i++)
            nums[i] = temp[i];
        
    }
    void mergesort(vector<pair<int, int>> &nums, vector<int> &cnt, int l, int r, vector<pair<int, int>>& temp)
    {
        if(r <= l)
            return;
        int m = (l+r)/2;
        mergesort(nums, cnt, l, m, temp);
        mergesort(nums, cnt, m+1, r, temp);
        merge(nums, cnt, l, m, r, temp);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> num;
        vector<pair<int, int>> temp(n+1);
        for(int i = 0; i <  n; i++)
            num.push_back({nums[i], i});
        vector<int> cnt(n, 0);
        mergesort(num, cnt, 0, n-1, temp);
        return cnt;
    }
};