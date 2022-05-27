class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int f1 = -1, f2 = -1;
        //f1 for second last fruit, f2 for last fruit encountered
        int same_fruit = 0, temp_ans = 0, ans = 0;
        for(auto f : fruits)
        {
            if(f == f1)
            {
                same_fruit = 1; //count for last fruit encountered is 1
                temp_ans++;
                f1 = f2;
                f2 = f; // since last fruit encountered is f
            }
            else if(f == f2)
            {
                same_fruit += 1;
                temp_ans++;
            }
            else
            {
                temp_ans = same_fruit + 1; // now answer willl be last fruit same count + 1 for new fruit
                same_fruit = 1; // new fruit encountered
                f1 = f2;
                f2 = f; // new fruit encountered is last fruit
            }
            ans = max(ans, temp_ans);
        }
        return ans;
        
    }
};