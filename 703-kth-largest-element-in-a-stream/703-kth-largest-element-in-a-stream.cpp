class KthLargest {
public:
    multiset<int, greater<int>> st;
    int K;
    KthLargest(int k, vector<int>& nums) {
        multiset<int, greater<int>> p(nums.begin(), nums.end());
        st = p;
        K = k;
    }
    
    int add(int val) {
        st.insert(val);
        int k = K;
        // cout<<k<<endl;
        for(auto itr = st.begin(); itr != st.end(); itr++)
        {
            if(k == 1)
                return *itr;
            k--;
        }
        return -1;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */