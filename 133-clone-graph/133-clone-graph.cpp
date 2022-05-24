/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // vector<bool> visited(101);
    bool visited[101];
    unordered_map<int, Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        Node* newNode;
        if(mp.find(node->val) != mp.end())
        {
            newNode = mp[node->val];
        }
        else
        {
            newNode = new Node(node->val);
            mp[node->val] = newNode;
        }
        visited[node->val] = true;
        for(Node* x : node->neighbors)
        {
            Node* nbr;
            if(!visited[x->val])
                nbr = cloneGraph(x);
            
            // if(mp.find(x->val) == mp.end()) 
            // {
            //     nbr = new Node(x->val);
            // }
            // else
            nbr = mp[x->val];
                
            newNode->neighbors.push_back(nbr);
        }
        return newNode;
    }
};