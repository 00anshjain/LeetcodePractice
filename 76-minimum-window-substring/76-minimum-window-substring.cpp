class Solution {
public:
    bool isCheck(unordered_map<char, int> &tmp, unordered_map<char, int> &smp)
    {
        for(auto x : tmp)
        {
            if(smp[x.first] < x.second)
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        unordered_map<char, int> tmp, smp;
        // string ans = "";
        int begin = -1, end = -1;
        int res = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            tmp[t[i]]++;
            smp[s[i]]++;    
        }
        bool flag = false;
        if(isCheck(tmp, smp))
        {
            flag = true;
            begin = 0;
            end = n-1;
            res = n;
        }
        int i = 0;
        for(int j = n; j < m; j++)
        {
            smp[s[j]]++;
            // cout<<s[j]<<"   "<<smp[s[j]]<<endl;
            if(!flag)
            {
                if(isCheck(tmp, smp))
                    flag = true;
            }
            if(flag)
            {
                while(smp[s[i]] > tmp[s[i]])
                {
                    smp[s[i]]--;
                    i++;
                }
                // cout<<smp[s[i]]<<" "<<tmp[s[i]]<<" "<<i<<" "<<j<<" "<<res<<endl;
                if(res > j-i+1)
                {
                    res = j-i+1;
                    begin = i;
                    end = j;
                }
            }
            // j++;
        }
        // cout<<res<<endl;
        if(begin == -1)
            return "";
        return s.substr(begin, res);
        
    }
};