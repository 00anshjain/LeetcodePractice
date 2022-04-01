class Solution {
public:
    long long timeToEatBanana(vector<int> &piles, long long int eatSpeed)
    {
        long long cnt = 0;
        for(int x : piles)
        {
            cnt += (x/eatSpeed + (x%eatSpeed > 0 ? 1 : 0));
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int right = 0;
        for(long long x : piles)
            right = max(right, x);
        int left = 1;
        long long int ans = -1;
        while(left <= right)
        {
            long long int mid = ((long long)left + right)/2;
            if(timeToEatBanana(piles, mid) <= h)
            {
                // cout<<"right = "<<right<<"  "<<timeToEatBanana(piles, mid)<<" "<<mid<<endl;
                ans = mid;
                right = mid  - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return (int)ans;
    }
};