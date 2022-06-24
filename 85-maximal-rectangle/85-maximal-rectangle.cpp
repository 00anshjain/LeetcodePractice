class Solution {
public:
    typedef int ll;
    int getAreaHistogram(vector<int> &ht, int n)
    {
        vector<int> stl(n, 0), str(n, n-1);
        stack<int> st1, st2;
        st1.push(0);
        st2.push(n-1);
        for(int i = 1; i < n; i++)
        {
            while(!st1.empty() && ht[st1.top()] >= ht[i])
                st1.pop();
            if(!st1.empty())
                stl[i] = st1.top() + 1;
            st1.push(i);
        }
        for(int i = n-2; i >= 0; i--)
        {
            while(!st2.empty() && ht[st2.top()] >= ht[i])
                st2.pop();
            if(!st2.empty())
                str[i] = st2.top()-1;
            st2.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans, ht[i]*(str[i] - stl[i] + 1));
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ht(m, 0);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == '0')
                    ht[j] = 0;
                else
                    ht[j] += 1;
            }
            ans = max(ans, getAreaHistogram(ht, m));
        }
        return ans;
        
    }
};