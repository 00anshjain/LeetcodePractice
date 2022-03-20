class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans = 0;
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int high = nums1.size();
        int low = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        while(high >= low)
        {
            int mid = (low+high)/2;
            int left1 = (mid != 0 ? nums1[mid - 1] : INT_MIN);
            int right1 = (mid != n1 ? nums1[mid] : INT_MAX);
            int cut2 = (n1+n2+1)/2 - mid; 
            // int left2 = (cut2 != 0 ? nums2[cut2 - 1] : INT_MIN);
            int left2 = (cut2 != 0 ? nums2[cut2 - 1] : INT_MIN);
            int right2 = (cut2 != n2 ? nums2[cut2] : INT_MAX);
            
            if(left1 > right2)
                high = mid - 1;
            else if(left2 > right1)
                low = mid + 1;
            else
            {
                if((n1 + n2) % 2)
                // {
                    return (double)max(left1, left2);
                // }
                // else
                // {
                    return ((double)max(left1, left2) + min(right1, right2))/2;
                // }
            }
        }
        return -1;
        
    }
};