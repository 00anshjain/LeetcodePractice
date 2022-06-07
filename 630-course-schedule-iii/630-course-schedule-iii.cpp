class Solution {
public:
    static bool cmp(const vector<int>&a, const vector<int>&b)
    {
        return a[1]<b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& c) {
        sort(c.begin(), c.end(), cmp);
        priority_queue<int>pq;
        
        int day = 0;
        for(int i=0;i<c.size();i++)
        {
            if(c[i][1] >= day + c[i][0])
            {
                day = day + c[i][0];
                pq.push(c[i][0]);
            }
            
            else if(!pq.empty() and pq.top() > c[i][0])
            {
                int temp = pq.top();
                pq.pop();
                day -= temp;
                day += c[i][0];
                pq.push(c[i][0]);
            }
        }
        return pq.size();
    }
};