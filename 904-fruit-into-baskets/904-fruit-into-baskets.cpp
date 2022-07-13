class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int f1 = -1, f2 = -1; //f1 is the main fruit, f2 is second fruit
        int ans = 0;
        int samefruit = 0, total = 0;
        for(auto x : fruits)
        {
            if(x == f1)
            {
                samefruit++;
                total++;
            }
            else if(x == f2)
            {
                total++;
                samefruit = 1;
                swap(f1, f2);
            }
            else
            {
                total = samefruit+1;
                f2 = f1;
                f1 = x;
                samefruit = 1;
            }
            ans = max(ans, total);
        }
        return ans;
    }
};