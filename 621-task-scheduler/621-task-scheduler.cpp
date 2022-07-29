class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(auto c : tasks)
            mp[c]++;
        priority_queue<int> pq;
        for(auto x : mp)
            pq.push(x.second);
        int cnt = 0;
        while(1)
        {
            vector<int> v;
            for(int i = 0; i <= n; i++)
            {
                if(!pq.empty())
                {
                    auto t = pq.top();
                    pq.pop();
                    cnt++;
                    t--;
                    if(t > 0)
                        v.push_back(t);
                }
                else
                {
                    if(v.empty())
                        return cnt;
                    cnt++;
                }
            }
            for(auto x : v)
                pq.push(x);
        }
        return cnt;
            
        
    }
};