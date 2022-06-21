class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0;
        int cnt2 = 0;
        int mx1 = INT_MIN, mx2 = INT_MIN;
        for(auto x : nums)
        {
            if(x == mx1)
                cnt1++;
            else if(x == mx2)
                cnt2++;
            else if(cnt1 == 0)
            {
                mx1 = x;
                cnt1 = 1;
            }
            else if(cnt2 == 0)
            {
                mx2 = x;
                cnt2 = 1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }   
        }
        vector<int> v;
        cnt1 = count(nums.begin(), nums.end(), mx1);
        if(cnt1 > nums.size()/3)
            v.push_back(mx1);
        cnt2 = count(nums.begin(), nums.end(), mx2);
        if(cnt2 > nums.size()/3)
            v.push_back(mx2);
        sort(v.begin(), v.end());
        return v;
        
        
    }
};