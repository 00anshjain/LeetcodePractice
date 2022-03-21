class Solution {
public:
    double poww(double x, long long n)
    {
        if(n == 0)
            return (double)1;
        if(n == 1)
            return x;
        if(n%2 == 1)
            return poww(x, n-1)*x;
        double k = poww(x, n/2);
        return k*k;
    }
    double myPow(double x, int n) {
        // if(n < 0)
        // cout<<abs(n)<<endl;
        double z = poww(x, abs((long long)n));
        if(n < 0)
            return 1.0/z;
        return z;
        
    }
};