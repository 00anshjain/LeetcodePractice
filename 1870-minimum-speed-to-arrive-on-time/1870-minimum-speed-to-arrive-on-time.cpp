class Solution {
public:
    typedef long long ll;
    int n;
    double error = 1e-9;
    // typedef long long ll;
    bool possible(int mid, vector<int>& dist, double hour)
    {
        // cout<<endl<<mid<<" ";
        for(int i = 0; i < n-1; i++)
        {
            //cout<<hour<<":"<<ceil(dist[i]/(double)mid)<<"   "<<endl;
            hour -= ceil(dist[i]/(double)mid);
            // cout<<hour<<endl;
            if(hour < 0)
                return false;
        }
        double z = hour - ((double)dist[n-1]/(double)mid);
        //cout<<hour<<":"<<((double)dist[n-1]/(double)mid)<<"   "<<endl;
        //cout<<hour - ((double)dist[n-1]/(double)mid);
        if(z >= 0 || (-1*z) < error)
        {
            
            // cout<<"  a   "<<(hour >= ((double)dist[n-1]/(double)mid));
            return true;
            
        }
        else
        {
            // cout<<"   b  "<<(hour >= ((double)dist[n-1]/(double)mid));
            return false;
        }
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        // ll sum = accumulate(dist.begin(), dist.end(), 0);
         n = dist.size();
        // int minSpeed = floor(sum/hour);
        // if(ceil(hour) < n)
        //     return -1;
        // while(true)
        // {
        //     double t = 0;
        //     for(int i = 0; i < n; i++)
        //     {
        //         ll x = dist[i];
        
        //         if(i == n-1)
        //             t = x/(double)minSpeed;
        //         else
        //             t += ceil(x/(double)minSpeed);
        //         if(t > hour)
        //             break;
        //     }
        //     if(t > hour)
        //         minSpeed++;
        //     else
        //         return minSpeed;
        // }
        int left = 1;
        int right = 1e7;
        if( hour <= n-1)
            return -1;
        int ans = left;
        
        while(left <= right)
        {
            int mid = (left + right)/2;
            if(possible(mid, dist, hour))
            {
                // cout<<"YES";
                ans = mid;
                right = mid - 1;
            }
            else
            {
                // cout<<"No";
                left = mid+1;
            }
        }
        return ans;
    }
};