// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    // int k = 1;
    int rand10() {
        int idx;
        do{
            int row = rand7();
            int col = rand7();
            idx = (row-1)*7 + col;
        } while(idx > 40);
        return 1 + idx%10;
        
    }
};