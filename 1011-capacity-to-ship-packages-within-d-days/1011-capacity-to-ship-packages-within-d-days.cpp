class Solution {
public:
    int noOfPartition(vector<int>& arr, int maxWt)
    {
        int partitions = 1, currSum = 0;
        for(auto x : arr)
        {
            currSum += x;
            if(currSum > maxWt)
            {
                partitions++;
                currSum = x;
            }
        }
        return partitions;
        
    }
    
    int shipWithinDays(vector<int>& arr, int days) {
        int mx = 0;
        int sum = 0;
        for(auto x : arr)
        {
            sum += x;
            mx = max(x, mx);
        }
        int ans = 0;
        int left = mx, right = sum;
        while(left <= right)
        {
            int mid = (left + right)/2;
            int k = noOfPartition(arr, mid);
            if(k <= days)
            {
                right = mid-1;
                ans = mid;
            }
            else// if(k > days)
            {
                left = mid+1;
            }
            // else
            //     return mid;
        }
        // ans = mid;
        return ans;
        
        
    }
};