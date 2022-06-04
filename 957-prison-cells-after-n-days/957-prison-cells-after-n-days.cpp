class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        // vector<int> g;
        // int k = cells.size();
        int k = 8;
        // while(n--)
        // {
        //     vector<int> g(cells.begin(), cells.end());
        //     for(int i = 0; i < 8; i++)
        //     {
        //         if(i-1 < 0 || i+1 >= 8)
        //             g[i] = 0;
        //         else
        //             g[i] = (1 - g[i+1]^g[i-1]);
        //         // else if(cells[i-1] == cells[i+1])
        //         //     g[i] = 1;
        //         // else
        //         //     g[i] = 0;
        //     }
        //     // g[0] = 0;
        //     // g[k-1] = 0;
        //     cells = g;
        // }
        // return cells;
        vector<int> ans(8);
        if(n == 0)
            return cells;
        // if(n > 0)
        // {
        ans[0] = 0;
        ans[7] = 0;
        unordered_map<int, int> mp;
        int j;
        int num;
        for(j = 0; j < n; j++)
        {
            vector<int> g(cells.begin(), cells.end());
            num = 0;
            for(int i = 0; i < 8; i++)
            {
                if(i-1 < 0 || i+1 >= 8)
                    g[i] = 0;
                else
                    g[i] = (1 - cells[i+1]^cells[i-1]);
                num = num + (g[i]<<i);
                // else if(cells[i-1] == cells[i+1])
                //     g[i] = 1;
                // else
                //     g[i] = 0;
            }
            if(mp.find(num) != mp.end())
                break;
            else
                mp[num] = j;
            // g[0] = 0;
            // g[k-1] = 0;
            cells = g;
        }
        if(j == n)
            return cells;
        int z = mp[num];
        int repeat = j-z;
        int reqd_n = (n-z) % repeat;
        
        for(int j = 0; j < reqd_n; j++)
        {
            vector<int> g(cells.begin(), cells.end());
            num = 0;
            for(int i = 0; i < 8; i++)
            {
                if(i-1 < 0 || i+1 >= 8)
                    g[i] = 0;
                else
                    g[i] = (1 - cells[i+1]^cells[i-1]);
                // num = num + (g[i]<<i);
            }
            cells = g;
        }
        return cells;
        // }
        
    }
};