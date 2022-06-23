class Solution {
public:
    bool recur(vector<int> &nums, int sum1, int sum2, bool turn, int i, int j)
    {
        if(i > j)
            return sum1 >= sum2;
        if(turn)
        {
            if(recur(nums, sum1 + nums[i], sum2, !turn, i+1, j) ||
                    recur(nums, sum1 + nums[j], sum2, !turn, i, j-1))
               return true;
            return false;
        }
        else
        {
            if((!recur(nums, sum1, sum2 + nums[i], !turn, i+1, j) ||
                    !recur(nums, sum1, sum2 + nums[j], !turn, i, j-1)))
                return false;
            return true;
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        int sum1 = 0, sum2 = 0;
        int n = nums.size();
        bool turn = true;
        return recur(nums, sum1, sum2, turn, 0, n-1);
        // int sum1 = 0, sum2 = 0;
        // int i = 0, j = nums.size() - 1;
        // bool flag = true;
        // while(i <= j)
        // {
        //     if(flag)
        //     {
        //         if(nums[i] >= nums[j])
        //             sum1 += nums[i++];
        //         else
        //             sum1 += nums[j--];
        //     }
        //     else
        //     {
        //         if(nums[i] >= nums[j])
        //             sum2 += nums[i++];
        //         else
        //             sum2 += nums[j--];
        //     }
        //     flag = !flag;
        // }
        // return sum1 >= sum2;
    }
};