class Solution {
public:
    int strStr(string haystack, string needle) {
        // int i = 0;
        int n = needle.size();
        int m = haystack.size(), j = 0;
        while(j < m)
        {
            if(needle[0] == haystack[j])
            {
                int i = 0;
                int k = j;
                while(i < n && k < m && haystack[k] == needle[i])
                {
                    i++;
                    k++;
                }
                if(i == n)
                    return j;
            }
            j++;
            // else i = 0;
            // j++;
            // if(i == n)
            //     return j-n;
        }
        return -1;
    }
};