class Solution {
public:
    #define INF 100000
    string pushDominoes(string d) {
        int n = d.size();
        vector<int> arr(n, n), brr(n, n);
        int cnt = n;
        for(int i = 0; i < n; i++)
        {
            if(d[i] == 'R')
            {
                arr[i] = 0;
                cnt = 0;
            }
            else if(d[i] == '.')
            {
                if(cnt != n)
                {
                    cnt++;
                    arr[i] = cnt;
                }
            }
            else
            {
                cnt = n;
                // arr[i] = n;
            }
        }
        // string ans(d);
        cnt = n;
        for(int i = n-1; i >= 0; i--)
        {
            if(d[i] == 'L')
            {
                brr[i] = 0;
                cnt = 0;
            }
            else if(d[i] == '.')
            {
                if(cnt != n)
                {
                    cnt++;
                    brr[i] = cnt;
                }
            }
            else
            {
                cnt = n;
                // arr[i] = n;
            }
        }
        // for(int i = 0; i < n; i++)
        //     cout<<arr[i]<<" ";
        // cout<<endl;
        // for(int i = 0; i < n; i++)
        //     cout<<brr[i]<<" ";
        
        string ans;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] < brr[i])
            {
                ans.push_back('R');
            }
            else if(arr[i] > brr[i])
            {
                ans.push_back('L');
            }
            else
            {
                ans.push_back('.');
            }
        }
        return ans;
    }
};