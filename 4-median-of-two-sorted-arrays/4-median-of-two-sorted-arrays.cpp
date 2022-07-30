class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        int left = 0, right = n1;
        int eleInLeft = (n1 + n2 + 1)/2;
        while(left <= right)
        {
            int mid = (left+right)/2;
            //mid is number of element of nums1 in the left
            int l1 = INT_MIN;
            if(mid > 0)
                l1 = nums1[mid-1];
            int r1 = INT_MAX;
            if(mid < n1)
                r1 = nums1[mid];
            int mid2 = eleInLeft - mid;
            // cout<<mid<<" "<<mid2<<endl;
            int l2 = INT_MIN;
            if(mid2 > 0)
                l2 = nums2[mid2-1];
            int r2 = INT_MAX;
            if(mid2 < n2)
                r2 = nums2[mid2];
            if(l1 > r2)
            {
                right = mid - 1;
                continue;
            }
            else if(l2 > r1)
            {
                left = mid + 1;
                continue;
            }
            else
            {
                // cout<<mid<<" "<<mid2<<endl;
                // cout<<l1<<" "<<l2<<" "<<r1<<" "<<r2<<endl;
                if((n1 + n2) % 2 != 0)
                    return max(l1, l2);
                else
                    return (max(l1, l2)+min(r1, r2))/2.0;
            }
        }
        return -1;
    }
};