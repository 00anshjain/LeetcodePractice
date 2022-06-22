class Solution {
public:
    int n;
    int findPeakElement(vector<int>& nums) {
        n = nums.size();
        return peak(nums, 0 , nums.size()-1);
    }
    int peak(vector<int>& v, int l, int r)
    {
        if(l == r)
            return l;
        int mid = (l+r)/2;
        if(mid > 0 && mid < n)
        {
            if(v[mid] > v[mid+1] && v[mid] > v[mid - 1])
                return mid;
            else if(v[mid] < v[mid-1])
                return peak(v, l, mid-1);
            else if(v[mid] < v[mid + 1])
                return peak(v, mid+1, r);
        }
        else if(mid == 0)
        {
            if(v[0] > v[1])
                return 0;
            return 1;
        }
        else if(mid == n-1)
        {
            if(v[n-2] > v[n-1])
                return n-2;
            return n-1;
        }
        return -1;
        // if(v[mid] > v[mid + 1])
        //     return peak(v, l , mid);
        // return peak(v, mid+1, r);
    }
};