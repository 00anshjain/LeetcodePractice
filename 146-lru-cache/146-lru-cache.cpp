class LRUCache {
public:
    class Node{
        public:
            int key;
            int value;
            Node* left;
            Node* right;
            Node(int k, int val)
            {
                key = k;
                value = val;
                left = NULL;
                right = NULL;
            }
    };
    int capacity, sz;
    unordered_map<int, Node*> mp;
    Node *head, *tail;
    LRUCache(int capacity) {
        this->capacity = capacity;
        sz = 0;
        // mp.clear();
        head = NULL; tail = NULL;
    }
    // void insert(int key, int val)
    // {
    //     Node* curr = new Node(key, val);
    //     if(!head)
    //     {
    //         head = tail = curr;
    //         // return;
    //     }
    //     else
    //     {
    //         tail->right = curr;
    //         curr->left = tail;
    //         tail = curr;
    //     }
    //     sz += 1;
    // }
    void insert(Node* curr)
    {
        // Node* curr = new Node(key, val);
        if(!head)
        {
            head = tail = curr;
            // return;
        }
        else
        {
            tail->right = curr;
            curr->left = tail;
            tail = curr;
        }
    }
    void deleteNode(Node* p)
    {
        if(p->left)
            p->left->right = p->right;
        else
            head = p->right;
        if(p->right)
            p->right->left = p->left;
        else
            tail = p->left;
        p->left = NULL;
        p->right = NULL;
    }
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        Node* p = mp[key];
        deleteNode(p);
        insert(p);
        return p->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
        {
            mp[key]->value = value;
            Node* p = mp[key];
            // p->value = value;
            deleteNode(p);
            insert(mp[key]);
        }
        else
        {
            Node* curr = new Node(key, value);
            if(sz == capacity)
            {
                mp.erase(head->key);
                deleteNode(head);
                sz--;
            }
            insert(curr);
            mp[key] = curr;
            sz++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */