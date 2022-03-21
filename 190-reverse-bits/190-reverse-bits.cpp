class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t t = 0;
        for(int i = 0; i < 32; i ++)
        {
            uint32_t bt = (1<<i) & n;
            if(bt > 0)
                t |= 1<<(31-i); 
        }
        return t;
    }
};