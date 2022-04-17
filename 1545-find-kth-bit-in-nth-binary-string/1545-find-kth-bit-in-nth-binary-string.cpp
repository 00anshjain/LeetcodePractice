class Solution {
public:
    int solve(int n, int k)
    {
        if(k == 1)
            return 0;
        int mid = pow(2, n-1);
        if(mid == k)
            return 1;
        else if(k < mid)
            return solve(n-1, k);
        else
            return !solve(n-1, mid*2 - k);
    }
    char findKthBit(int n, int k) {
        return solve(n, k) + '0';
    }
};