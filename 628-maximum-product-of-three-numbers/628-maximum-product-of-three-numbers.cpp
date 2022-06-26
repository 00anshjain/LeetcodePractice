class Solution {
public:
    int maximumProduct(vector<int>& A) {
        if(A.size() == 3)
            return A[0]*A[1]*A[2];
        int mx = INT_MIN;
        int mx2 = INT_MIN;
        int mx3 = INT_MIN;
        int mn = INT_MAX;
        int mn2 = INT_MAX;;
        int cnt_neg = 0;
        for(auto x : A)
        {
            if(x > mx)
            {
                mx3 = mx2;
                mx2 = mx;
                mx = x;
            }else if(x > mx2)
            {
                mx3 = mx2;
                mx2 = x;
            }
            else if(x > mx3)
            {
                mx3 = x;
            }
            if(x < mn)
            {           
                mn2 = mn;
                mn = x;
            }else if(x < mn2)
            {
                mn2 = x;
            }
        }
        return max(mx*mn*mn2, mx*mx2*mx3);
    }
};