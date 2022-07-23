class Solution {
public:
    void merge(vector<pair<int, int>> &arr, int l, int mid, int r, vector<int>& cnt, vector<pair<int, int>>& temp)
    {
        int curr = 0;
        // vector<pair<int, int>> temp(r+1);
        int i = l, j = mid+1;
        int k = l;
        while(i <= mid && j <= r)
        {
            if(arr[i].first > arr[j].first)
            {
                temp[k++] = arr[j++];
                curr++;//inversion here
            }
            else
            {
                cnt[arr[i].second] += curr;
                temp[k++] = arr[i++];
            }
        }
        while(i <= mid)
        {
            cnt[arr[i].second] += curr;
            temp[k++] = arr[i++];
        }
        while(j <= r)
        {
            temp[k++] = arr[j++];
        }
        for(int i =l; i <= r; i++)
        {
            arr[i] = temp[i];
        }
    }
    void mergeSort(vector<pair<int, int>> &arr, int l, int r, vector<int>& cnt, vector<pair<int, int>>& temp)
    {
        if(l >= r)
            return;
        int mid = (l+r)/2;
        mergeSort(arr, l, mid, cnt, temp);
        mergeSort(arr, mid+1, r, cnt, temp);
        merge(arr, l, mid, r, cnt, temp);
        
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n, 0);
        vector<pair<int, int>> arr;
        vector<pair<int, int>> temp(n+1);
        for(int i = 0; i < n; i++)
        {
            arr.push_back({nums[i], i});
        }
        mergeSort(arr, 0, n-1, cnt, temp);
        return cnt;
    }
};