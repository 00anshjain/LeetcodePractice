class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        // if(n < 2)
        //     return 0;
        vector<int> aAhead(n+1, 0);
        vector<int> bTillHere(n+1, 0);  //is position tak kitne B aa gaye
        int curr = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'b')
            {
                curr += 1;
            }   
            bTillHere[i] = curr;
        }
        curr = 0;
        aAhead[n-1] = 0;
        // is position se aage kitne head h
        for(int i = n-1; i >= 0; i--)
        {
            if(s[i] == 'a')
            {
                curr += 1;
            }   
            aAhead[i] = curr;
        }
        // we will say ki a yaha tak h aage B dalane h ab
        int ans = min(aAhead[0], bTillHere[n-1]);// for all a and all b string
        for(int i = 0; i < n-1; i++)
        {
            ans = min(ans, aAhead[i+1] + bTillHere[i]);
        }
        return ans;
    }
};