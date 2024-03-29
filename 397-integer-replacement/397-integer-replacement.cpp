class Solution {
public:
    int integerReplacement(int n) {
        if(n == INT_MAX)
            return 32;
        if(n <= 3)
            return n-1;
        if(n%2 == 0)
            return 1 + integerReplacement(n/2);
        if((n+1)%4 == 0)
            return 1 + integerReplacement(n+1);
        return 1 + integerReplacement(n-1);
    }
};