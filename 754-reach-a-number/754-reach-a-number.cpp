class Solution {
public:
    int reachNumber(int target) {
        if(target > 0)
            target = -1*target;
        if(target == 0)
            return 0;
        int i = 0;
        while(target < 0)
            target += (++i);
        if(target %2 == 0)
            return i;
        else 
            return i + 1 + i%2;
    }
};