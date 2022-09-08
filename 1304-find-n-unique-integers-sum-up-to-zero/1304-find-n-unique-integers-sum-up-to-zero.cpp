class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> arr(n, 0);
        if(n == 1)
            return arr;
        int sum = 0;
        if(n == 2)
            return {1, -1};
        for(int i = 1; i < n-1; i++)
        {
            arr[i] = i;
            sum += i;
        }
        arr[n-1] = -1*sum;
        return arr;
    }
};