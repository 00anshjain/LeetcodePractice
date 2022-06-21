class Solution {
public:
    int binarySearch(vector<int> &stones, int l, int r, int val)
    {
        // int ans = -1;
        while(l <= r)
        {
            int mid = (l + r)/2;
            if(stones[mid] == val)
                return mid;
            else if(stones[mid] > val)
                r = mid - 1;
            else if(stones[mid] < val)
                l = mid + 1;
        }
        return -1;
    }
    bool recur(vector<int> &stones, int i, int k, int n, vector<vector<int>>& dp)
    {
        // cout<<stones[i]<<" "<<k<<endl;
        if(k <= 0)
            return false;
        if(i == n-1)
            return true;
        if(dp[i][k] != -1)
            return dp[i][k];
        // bool ans = false;
        int j = binarySearch(stones, i+1, n-1, stones[i] + k);
        if(j != -1)
        {
            if(recur(stones, j, k, n, dp))
            {   
                return true;
            }
        }
        j = binarySearch(stones, i+1, n-1, stones[i] + k+1);
        if(j != -1)
        {
            if(recur(stones, j, k+1, n, dp))
                return true;
        }
        j = binarySearch(stones, i+1, n-1, stones[i] + k-1);
        if(j != -1)
        {
            if(recur(stones, j, k-1, n, dp))
                return true;
        }
        return dp[i][k] = false;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(n == 1)
            return true;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        if(stones[1] != 1)
            return false;
        return recur(stones, 1, 1, n, dp);
        
    }
};