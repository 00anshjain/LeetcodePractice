class Solution {
public:
    bool isPalindrome(int x) {
        int y = x;
        long long z = 0l;
        while(y > 0)
        {
            z *= 10;
            z += y%10;
             y/= 10;
        }
        if(x == z)
            return true;
        return false;
    }
};