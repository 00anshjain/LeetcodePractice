class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(c > 0)
            pq.push({c, 'c'});
        if(b > 0)
            pq.push({b, 'b'});
        if(a > 0)
            pq.push({a, 'a'});
        string ans = "";
        char last = 'z';
        while(!pq.empty())
        {
            auto t = pq.top();
            pq.pop();
            char c1 = t.second;
            int f1 = t.first;
            // cout<<c1<<endl;
            if(pq.empty())
            {
                if(last == c1)
                    break;
                int k = min(2, f1);
                while(k-- > 0)
                    ans += c1;
                break;
            }
            t = pq.top();
            pq.pop();
            char c2 = t.second;
            // cout<<c2<<endl;
            int f2 = t.first;
            // cout<<f1<<" "<<f2<<endl;
            if(last != c1)
            {
                int k = min(2, f1);
                int F1 = f1;
                f1 -= k;
                while(k-- > 0)
                    ans += c1;
                if(f1 > 0)
                    pq.push({f1, c1});
                k = 1;
                if(F1 - f2 <= 2)
                    k = min(2, f2);
                // f2--;
                f2 -= k;
                while(k-- > 0)
                    ans += c2;
                // ans += c2;
                if(f2 > 0)
                    pq.push({f2, c2});
                last = c2;
            }
            else// if(last != c2)
            {
                int k = 1;
                if(f1 - f2 <= 2)
                    k = min(2, f2);
                // f2--;
                f2 -= k;
                while(k-- > 0)
                    ans += c2;
                // ans += c2;
                if(f2 > 0)
                    pq.push({f2, c2});
                k = min(2, f1);
                f1 -= k;
                while(k-- > 0)
                    ans += c1;
                if(f1 > 0)
                    pq.push({f1, c1});
                last = c1;
            }
        }
        return ans;
        
    }
};