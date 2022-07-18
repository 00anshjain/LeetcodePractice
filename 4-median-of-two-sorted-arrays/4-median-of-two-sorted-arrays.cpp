class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int low = 0, high = n;  
        if(n > m)
            return findMedianSortedArrays(nums2, nums1);
        // 1, 3, 4, 5, 8, 10, 12 
       // ^  ^  ^  ^  ^  ^   ^  ^
        // 2, 3, 6, 15
        int lcount = (n+m+1)/2;//+1 because we want more lements towards left when odd elements total
        while(low <= high)
        {
            int mid = (low+high)/2;
            int cut2 = lcount - mid; 
            int left1 = INT_MIN, left2 = INT_MIN, right1 = INT_MAX, right2 = INT_MAX;
            if(mid > 0)
                left1 = nums1[mid-1];
            if(mid != n)
                right1 = nums1[mid];
            if(cut2 != 0)
                left2 = nums2[cut2 - 1];
            if(cut2 != m)
                right2 = nums2[cut2];
            if(left1 > right2)
                high = mid - 1;
            else if(left2 > right1)
                low = mid + 1;
            else
            {
                if((n+m)%2 == 0)
                    return ((double)(max(left1, left2)) + min(right1, right2))/2;
                else
                    return max(left1, left2);
            }
            
        }
        return -1;
        
    }
};