class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int n = nums.size();
        int ans = 2;
        // for(int freq = 1; freq < n; freq++)
        int freq = 1;
        // {
        // for(int i = 0; i < n; i++)
        int i = 0;
        // {
        //unordered_
        map<int, int> mp;
        int unq = 0, freqMatch = 0;
        int over = 0;
        for(int j = 0; j < n; j++)
        {
            mp[nums[j]]++;
            if(mp[nums[j]] == 1)
                unq++;
            if(mp[nums[j]] == freq)
                freqMatch++;
            
            if(mp[nums[j]] == freq+1)
            {
                over++;
                if(unq == freqMatch)
                {
                    // over++;
                    if(over > 1)
                    {
                        freq++;
                        over = 0;
                        freqMatch = 2;
                    }
                }
                else
                {
                    freq++;
                    freqMatch = over;
                    over = 0;
                }
            }
            else if(mp[nums[j]] > freq+1)
            {
                if(unq == freqMatch)
                {
                    if(over == 1)
                    {
                        freq++;
                        over = 1;
                        freqMatch = 1;
                    }
                    else// if(over == 2)
                    {
                        freq++;
                        over = 1;
                        freqMatch = 2;
                    }
                }
                else
                {
                    over = 0;
                    freq = freq+2;
                    freqMatch = 0;
                }
            }
            if(freq == 1 && (j-i+1) == freqMatch*freq)
            {
                ans = max(ans, j-i+1);
                // cout<<"j ="<<j<<" freq="<<freq<<" "<<freqMatch<<"  over="<<over<<endl;
            }
            if(j-i+1 == freqMatch*freq + 1)
            {
                ans = max(ans, j-i+1);
                // cout<<"j ="<<j<<" freq="<<freq<<" "<<freqMatch<<"  over="<<over<<endl;
            }
        }
        // }
        // }
        // for(auto x : mp)
        //     cout<<x.first<<" "<<x.second<<endl;
        return ans;
    }
};