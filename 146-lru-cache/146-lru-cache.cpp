class LRUCache {
public:
    struct Node{
        int key;
        int val;
        Node* left;
        Node* right;
         
        Node(int key, int value)
        {
            this->key = key;
            this->val = value;
            left = NULL;
            right = NULL;
        }
    };
    unordered_map<int, Node*> mp;
    int cap, size;
    Node* head, *tail;
    void deleteNode(Node* p)
    {
        if(p->left != NULL)
            p->left->right = p->right;
        else
        {
            head = p->right;
            // if(head)
            //     head->left = NULL;
        }
        if(p->right != NULL)
            p->right->left = p->left;
        else
            tail = p->left;
        
        p->left = NULL;
        p->right = NULL;
        size--;
    }
    void insertNode(Node* p)
    {
        size++;
        if(!head)
        {
            head = tail = p;
            // p->left = NULL;
            // p->right = NULL;
            return;
        }
        tail->right = p;
        p->left = tail;
        tail = p;
        return;
    }
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = NULL;
        tail = NULL;
    }
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        Node* p = mp[key];
        deleteNode(p);
        insertNode(p);
        return p->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
        {
            Node* p = mp[key];
            deleteNode(p);
            p->val = value;
            mp[key] = p;
            insertNode(p);
        }
        else
        {
            Node* p = new Node(key, value);
            mp[key] = p;
            if(size < cap)
            {
                insertNode(p);
                return;
            }
            mp.erase(head->key);
            deleteNode(head);
            insertNode(p);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */