class Solution {
public:
    typedef vector<int> vi;
    vector<int> smallestRange(vector<vector<int>>& arr) {
        int k = arr.size();
        // int n = arr[0].size();
        priority_queue<vi, vector<vi>, greater<vi>> pq;
        int mx = 0;
        int len = INT_MAX;
        vector<int> pr;
        for(int j = 0; j < k; j++)
        {
            pq.push({arr[j][0], j, 0});
            mx = max(mx, arr[j][0]);
        }
        while(1)
        {
            auto v = pq.top();
            pq.pop();
            int num = v[0];
            int i = v[1];
            int j = v[2];
            if(len > mx - num)
            {
                len = mx - num;
                pr = {num, mx};
                // cout<<pr[0]<<" "<<pr[1]<<" "<<j<<" "<<n-1<<endl;
            }
            if(j == arr[i].size()-1)
                break;
            pq.push({arr[i][j+1], i, j+1});
            if(arr[i][j+1] > mx)
                mx = arr[i][j+1];
        }
        return pr;
        
    }
};