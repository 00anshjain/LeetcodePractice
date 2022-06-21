class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        int fact[n+1];
        vector<int> num;
        fact[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            num.push_back(i);
            fact[i] = i*fact[i-1];
        }
        // bool taken[n+1];
        
        // memset(taken, false, sizeof(taken));
        string ans = "";
        while(n > 0)
        {
            // int j = 1;
            // while(taken[j])
            //     j++;
            int z = k/fact[n-1];
            ans += to_string(num[z]);
            num.erase(num.begin() + z);
            k %= fact[n-1];
            
//             {
//                 k -= fact[n-1];
//                 j++;
//                 while(taken[j])
//                     j++;
            
//             }
//             taken[j] = true;
            // ans += to_string(j);
            n--;
        }
        return ans;
    }
};