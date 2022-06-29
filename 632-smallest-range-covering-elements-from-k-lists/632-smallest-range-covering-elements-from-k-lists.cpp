class Solution {
public:
    // typedef vector<int> vi;
    struct element{
        int num;
        int i;
        int j;
        int n;
        element(int a, int b, int c, int d)
        {
            num = a;
            i = b;
            j = c;
            n = d;
        }
    };
    struct compare{
      bool operator()(element &a, element &b)
      {
          return a.num > b.num;
      }
    };
    
    vector<int> smallestRange(vector<vector<int>>& arr) {
        int k = arr.size();
        // int n = arr[0].size();
        priority_queue<element, vector<element>, compare> pq;
        int mx = INT_MIN;
        int len = INT_MAX;
        vector<int> pr;
        for(int j = 0; j < k; j++)
        {
            pq.push(element(arr[j][0], j, 0, arr[j].size()));
            mx = max(mx, arr[j][0]);
        }
        while(!pq.empty())
        {
            element v = pq.top();
            pq.pop();
            int num = v.num;
            int i = v.i;
            int j = v.j;
            int n = v.n;
            if(len > mx - num)
            {
                len = mx - num;
                pr = {num, mx};
                // cout<<pr[0]<<" "<<pr[1]<<" "<<j<<" "<<n-1<<endl;
            }
            if(j == n-1)
                break;
            pq.push(element(arr[i][j+1], i, j+1, n));
            if(arr[i][j+1] > mx)
                mx = arr[i][j+1];
        }
        return pr;
        
    }
};