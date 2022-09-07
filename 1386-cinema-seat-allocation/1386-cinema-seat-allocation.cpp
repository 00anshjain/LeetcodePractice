class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& seats) {
        // vector<int> arr(n+1, 0);
        unordered_map<int, int> arr;
        for(auto v : seats)
            arr[v[0]] |= (1<<v[1]);
        int ans = 0;
        int start4 = 0, end4 = 0, mid4 = 0;
        start4 |= 1<<2; start4 |= 1<<3; start4 |= 1<<4; start4 |= 1<<5;
        mid4 |= 1<<4; mid4 |= 1<<5; mid4 |= 1<<6; mid4 |= 1<<7;
        end4 |= 1<<6; end4 |= 1<<7; end4 |= 1<<8; end4 |= 1<<9;
        ans = 2*n;// as each row can have maxm of two families
        // start4 = ~start4; mid4 = ~mid4; end4 = ~end4;
        for(auto x : arr)
        {
            // int row = x.first;
            int mask = x.second;
            int cnt = 0;
            if((start4 & mask) == 0)
                cnt++;
            if((end4 & mask) == 0)
                cnt++;
            if(cnt == 2)
                continue;
            // else 
            if(cnt == 1)
            {
                ans--;
            }
            else if(cnt == 0 && (mid4 & mask) == 0)
            {
                ans--;
            }
            else if(cnt == 0)
                ans -= 2;
                // cout<<"here"<<endl;
                // ans += 2 cnt;
                // cout<<ans<<endl;
                // continue;
            // }
            // else if((mid4 & arr[i]) == 0)
            //     ans++;
        }
        // cout<<ans<<endl;
        return ans;
        
    }
};