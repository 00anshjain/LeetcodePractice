class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> arr;
        int f = 1, s = 1;
        arr.push_back(1);
        while(1)
        {
            int num = f + s;
            if(num > k)
                break;
            if(num == k)
                return 1;
            arr.push_back(num);
            s = num;
            swap(f, s);
        }
        int j = arr.size() - 1;
        int cnt = 0;
        while(j >= 0)
        {
            if(arr[j] <= k)
            {
                cnt++;
                k -= arr[j];
            }
            else
                j--;
        }
        return cnt;
    }
};