class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double tax = 0;
        int i = 0, n = brackets.size();
        while(i < n && income > 0)
        {
            int taxable;
            if(i == 0)
                taxable = min(income, brackets[i][0]);
            else
                taxable = min(income, brackets[i][0] - brackets[i-1][0]);
            tax += ((double)taxable*(brackets[i][1])/100);
            // cout<<taxable<<" "<<((double)taxable*(brackets[i][1])/100)<<endl;
            income -= taxable;
            i++;
        }
        return tax;
    }
};