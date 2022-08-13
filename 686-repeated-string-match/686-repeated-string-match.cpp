class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n1 = a.size();
        int n2 = b.size();
        int j = 0;
        int start = 0;
        // int ans = -1;
        while(start < n1)
        {
            while(start < n1 && a[start] != b[0])
                start++;
            // cout<<start<<endl;
            if(start == n1)
                break;
            int j = start, i = 0;
            int cnt = 1;
            for(i = 0; i < n2; i++)
            {
                if(j == n1)
                {
                    j = 0;
                    cnt++;
                }
                if(a[j] != b[i])
                {
                    cnt = -1;
                    break;
                }
                j++;
            }
            // cout<<start<<" "<<cnt<<endl;
            if(cnt != -1)
                return cnt;
            start++;
            // if(ans != -1)
            //     break;
        }
        return -1;
    }
};