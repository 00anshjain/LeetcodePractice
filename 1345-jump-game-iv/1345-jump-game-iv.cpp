class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n == 1)
            return 0;
        queue<int> q;
        q.push(0);
        int turn = 0;
        vector<bool> visited(n, false);
        visited[0] = true;
        unordered_map<int, list<int>> mp;
        for(int i = 0; i < n; i++)
            mp[arr[i]].push_back(i);
        while(!q.empty())
        {
            int sz = q.size();
            turn++;
            while(sz--)
            {
                int t = q.front();
                q.pop();
                for(auto k : mp[arr[t]])
                {
                    if(!visited[k])
                    {
                        if(k == n-1)
                            return turn;
                        q.push(k);
                        visited[k] = true;
                    }
                }
                mp[arr[t]].clear();
                if(t-1 > 0 && !visited[t-1])
                {
                    q.push(t-1);
                    visited[t-1] = true;

                }
                if(t+1 < n && !visited[t+1])
                {
                    if(t+1 == n-1)
                        return turn;
                    q.push(t+1);
                    visited[t+1] = true;
                }
            }
            
        }
        return -1;
    }
};