class NumArray {
public:
    // int seg[4e5+1];
    vector<int> seg;
    int n;
    void buildSeg(vector<int>& nums, int idx, int l, int r)
    {
        if(l == r)
        {
            seg[idx] = nums[l];
            return;
        }
        int mid = (l+r)/2;
        buildSeg(nums, 2*idx+1, l, mid);
        buildSeg(nums, 2*idx+2, mid+1, r);
        // cout<<"here 1"<<"  ";
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
        // cout<<"2"<<endl;
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(6*n+1, 0);
        // cout<<endl;
        buildSeg(nums, 0, 0, n-1);
    }
    void pointUpdate(int idx, int l, int r, int index, int value)
    {
        if(l > index || r < index)
            return;
        if(l ==r)
        {
            seg[idx] = value;
            return;
        }
        int mid = (l+r)/2;
        pointUpdate(2*idx+1, l, mid, index, value);
        pointUpdate(2*idx+2, mid+1, r, index, value);
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }
    void update(int index, int val) {
        pointUpdate(0, 0, n-1, index, val);
    }
    
    int getQuery(int idx, int l, int r, int low, int high) //l and r is window in array, // low to high is what we want
    {
        if(l > high || r < low)
            return 0;
        if(low <= l && high >= r)
            return seg[idx];
        int mid = (l+r)/2;
        return getQuery(2*idx+1, l, mid, low, high) + getQuery(2*idx+2, mid+1, r, low, high);
    }
    int sumRange(int left, int right) {
        return getQuery(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */