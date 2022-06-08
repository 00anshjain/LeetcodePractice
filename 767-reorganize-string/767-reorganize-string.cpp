class Solution {
public:
    string reorganizeString(string s) {
        int mx = 0;
        int n = s.size();
        unordered_map<char, int> mp;
        for(auto c : s)
        {
            mp[c]++;
            mx = max(mx, mp[c]);
        }
        if(mx > (n+1)/2)
            return "";
        priority_queue<pair<int, char>> pq;
        for(auto x : mp)
            pq.push({x.second, x.first});
        string ans = "";
        char last = 'A';
        while(pq.size() > 1)
        {
            char ch1 = pq.top().second;
            int f1 = pq.top().first;
            pq.pop();
            char ch2 = pq.top().second;
            int f2 = pq.top().first;
            pq.pop();
            if(last != ch1)
            {
                ans += ch1;
                ans += ch2;
                last = ch2;
                
            }
            else
            {
                ans += ch2;
                ans += ch1;
                last = ch1;
                
            }
            if(f1-1 > 0)
                pq.push({f1-1, ch1});
            if(f2-1 > 0)
                pq.push({f2-1, ch2});
        }
        if(!pq.empty())
        {
            ans += pq.top().second;
        }
        return ans;
    }
};