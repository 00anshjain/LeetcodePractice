class Solution {
public:
    int BS(vector<int>& arr, int left, int right, int t)
    {
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(arr[mid] == t)
                return mid;
            else if(arr[mid] < t)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int left = 0, right = n - 1;
        int mnEle;
        while(left <= right)
        {
            if(arr[left]<= arr[right])
            {
                mnEle = left;
                break;
            }
            int mid = left + (right - left)/2;
            if(arr[mid] <= arr[(mid+1)%n] && arr[mid] <= arr[(mid-1+n)%n])
            {
                mnEle = mid;
                break;
            }
            if(arr[left]<= arr[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
        int ans = BS(arr, 0, mnEle-1, target);
        if(ans != -1)
            return ans;
        else return BS(arr, mnEle, n-1, target);
        
    }
};