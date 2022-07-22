class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int a)
    {
        data = a;
        left = NULL;
        right = NULL;
    }
};
class KthLargest {
public:
    Node* head = NULL;
    int K;
    
    Node* makeBST(vector<int> &nums, int l, int r)
    {
        if(l > r)
            return NULL;
        if(l == r)
            return new Node(nums[l]);
        int mid = l + (r-l)/2;
        Node* root = new Node(nums[mid]);
        root->left = makeBST(nums, l, mid-1);
        root->right = makeBST(nums, mid+1, r);
        return root;
    }
    KthLargest(int k, vector<int>& nums) {
        sort(nums.begin(), nums.end());
        head = makeBST(nums, 0, nums.size() - 1);
        K = k;
    }
    
    Node* addValue(int val, Node* root)
    {
        if(!root)
            return new Node(val);
        if(root->data < val)
        {
            root->right = addValue(val, root->right);
            return root;
        }
        else if(root->data >= val)
        {
            root->left = addValue(val, root->left);
            return root;
        }
        return NULL;
    }
    int DFS(Node* root, int &k)
    {
        if(!root)
            return -1;
        int l = DFS(root->right, k);
        if(l != -1)
            return l;
        k--;
        if(k == 0)
            return root->data;
        return DFS(root->left, k);
    }
    int add(int val) {
        head = addValue(val, head);
        int k = K;
        // cout<<k<<endl;
        return DFS(head, k);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */