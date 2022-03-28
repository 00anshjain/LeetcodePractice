class Solution {
public:
    int n;
    void helper(int k, vector<int>& vec)
    {
        if(k > n)
            return;
        // cout<<k<<" ";
        vec.push_back(k);
        k *= 10;
        // cout<<k<<"     "<<endl;
        if(k > n)
            return;
        for(int i = 0; i < 10; i++)
        {
            if(k + i <= n)
                helper(k + i, vec);
        }
    }
    vector<int> lexicalOrder(int z) {
        n = z;
        vector<int> vec;
        for(int i = 1; i < 10; i ++)
        {
            helper(i, vec);
        }
        
        return vec;
    }
};