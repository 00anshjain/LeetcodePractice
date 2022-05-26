class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size())
            return {};
        int pArr[26] = {0};
        int sArr[26] = {0};
        
        // vector<int> pArr(26, 0);
        // vector<int> sArr(26, 0);
        int psize = p.size();
        int n = s.size();
        for(int i = 0; i < psize; i++)
        {
            pArr[p[i]-'a']++;
            sArr[s[i]-'a']++;
        }
        vector<int> res;
        // if(pArr == sArr)
        bool flag = true;
        for(int i = 0; i < 26; i++)
        {
            if(pArr[i] != sArr[i])
            {
                flag = false;
                break;
            }
        }
        if(flag)
            res.push_back(0);
        int i = 0;
        for(int j = psize; j < n; j++)
        {
            flag = true;
            sArr[s[j]-'a']++;
            sArr[s[i]-'a']--;
            i++;
            bool flag = true;
            for(int i = 0; i < 26; i++)
            {
                if(pArr[i] != sArr[i])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                res.push_back(i);

            // if(pArr == sArr)
            //     res.push_back(i);
        }
        return res;
        
    }
};