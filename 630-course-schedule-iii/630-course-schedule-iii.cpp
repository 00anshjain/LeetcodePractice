class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b)
    {
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& c) {
        sort(c.begin(), c.end(), comp);
        priority_queue<int> pq;
        int day = 0;
        // int cnt = 0;
        for(auto x : c)
        {
            // cout<<x[0]<<"  "<<x[1]<<endl;
            if((day + x[0]) <= x[1])
            {
                // cnt++;
                day += x[0];
                pq.push(x[0]);
                // cout<<"  "<<day<<endl;
            }
            else
            {
                if(!pq.empty() && pq.top() > x[0])
                {
                    day = (day -pq.top() +x[0]);
                    pq.pop();
                    pq.push(x[0]);
                    // cout<<" taken  "<<day<<endl;
                }
            }
        }
        return pq.size();
    }
};