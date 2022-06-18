class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if(n == 1)
            return true;
        if(s[n-1] == '1')
            return false;
        int pre[n+1];
        memset(pre, 0, sizeof(pre));
        pre[0] = 1;
        pre[1] = -1;
        if(minJump < n)
            pre[minJump]++;
        if(maxJump+1 < n)
            pre[maxJump+1]--;
        
        for(int i = 1; i < n ;i++)
        {
            pre[i] += pre[i-1];
            if(s[i] == '0' && pre[i] > 0)
            {
                if(i + minJump < n)
                    pre[i + minJump]++;
                if(i + maxJump+1 < n)
                    pre[i + maxJump + 1]--;
            }
        }
        return pre[n-1] > 0;
    }
};