class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // int ans = 0;
        int arr[501];
        memset(arr, 0, sizeof(arr));
        for(auto x : nums)
        {
            arr[x]++;
        }
        for(int i = 1; i <= 500; i++)
        {
            if(arr[i] %2 == 1)
                return false;
        }
        return true;
        // for(int x:nums)
        //     ans ^= x;
        // // return ans==0 ? true:false;
        // map<int, int> m;
        // for(int x : nums)
        //     m[x]++;
        // ans = 0;
        // for(auto it=m.begin(); it != m.end(); it++)
        // {
        //     if(it->second%2==1)
        //     {
        //         ans ^= it->first;
        //         cout<<it->first<<" "<<it->second<<'\n';
        //     }
        // }
        // cout<<ans<<endl;
        return 0;
    }
};