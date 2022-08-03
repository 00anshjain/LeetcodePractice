class Solution {
public:
    int closestMeetingNode(vector<int>& e, int node1, int node2) {
        int n = e.size();
        vector<int> visit(n, -1);
        queue<pair<int, int>> q;
        q.push({node1, 1});
        q.push({node2, 2});
        int ans = INT_MAX;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
            auto t = q.front();
            int num = t.second;
            int node = t.first;
            // cout<<node<<" "<<num<<endl;
            q.pop();
            if(node == -1)
                continue;
            if(visit[node] == -1)
            {
                visit[node] = num;
                q.push({e[node], num});
            }
            else if(visit[node] != num)
            {
                ans = min(ans, node);
            }
            else
                continue;
            }
            if(ans != INT_MAX)
                return ans;
            // continue;
        }
        return -1;
    }
};