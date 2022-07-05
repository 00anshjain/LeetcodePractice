class Solution {
public:
    int candy(vector<int>& rat) {
        int n = rat.size();
        vector<int> arr(n, 1);
        // memeset(arr, 1, sizeof(arr));
        // arr[0] = 1;
        for(int i = 1; i < n; i++)
        {
            if(rat[i] > rat[i-1])
                arr[i] = 1 + arr[i-1];
        }
        for(int i = n-2; i >= 0; i--)
        {
            if(rat[i] > rat[i+1])
                arr[i] = max(arr[i], 1 + arr[i+1]);
        }
        // for(int i = 0; i< n; i++)
        //     cout<<arr[i]<<" ";
        return accumulate(arr.begin(), arr.end(), 0);
        
    }
};