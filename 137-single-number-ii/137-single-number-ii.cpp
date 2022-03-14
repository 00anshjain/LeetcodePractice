class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int tn = -1, tnp1 = 0, tnp2 = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int cwtn = nums[i] & tn;
            int cwtnp1 = nums[i] & tnp1;
            int cwtnp2 = nums[i] & tnp2;
            
            tn = tn & (~cwtn);
            tnp1 = tnp1 | (cwtn);
            
            tnp1 = tnp1 & (~cwtnp1);
            tnp2 = tnp2 | (cwtnp1);
            
            tnp2 = tnp2 & (~cwtnp2);
            tn = tn | (cwtnp2);
        }
        return tnp1;
    }
};