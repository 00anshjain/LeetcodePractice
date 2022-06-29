class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for(auto c : s)
            mp[c]++;
        int n = s.size();
        priority_queue<pair<int, char>> pq;
        char last = '0';
        for(auto x : mp)
            pq.push({x.second, x.first});
        if(pq.top().first > (n+1)/2)
            return "";
        string ans = "";
        while(!pq.empty())
        {
            auto [f1, w1] = pq.top();
            pq.pop();
            if(pq.empty())
            {
                if(last == w1)
                    return "";
                ans += w1;
                if(f1 > 1)
                    return "";
                return ans;
            }
            auto [f2, w2] = pq.top();
            pq.pop();
            if(last == w1)
            {
                ans += w2;
                ans += w1;
            }else
            {
                ans += w1;
                ans += w2;
                last = w2;
            }
            if(f1 > 1)
                pq.push({f1-1, w1});
            if(f2 > 1)
                pq.push({f2-1, w2});
        }
        return ans;
        
        
    }
};