class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = -1;
        int freq = 1;
        for(auto ch : nums)
        {
            if(ch == c)
                freq++;
            else
                freq--;
            if(freq == 0)
            {
                c = ch;
                freq = 1;
            }
        }
        return c;
    }
};