/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        unordered_map<Node*, Node*> mp;
        Node* newHead = new Node(head->val);
        Node* curr = head;
        Node* newCurr = newHead;
        mp[head] = newHead;
        curr = curr->next;
        while(curr)
        {
            Node* newNode = new Node(curr->val);
            mp[curr] = newNode;
            newCurr->next = newNode;
            curr = curr->next;
            newCurr = newCurr->next;
        }
        curr = head;
        newCurr = newHead;
        while(curr)
        {
            newCurr->random = mp[curr->random];
            curr = curr->next;
            newCurr = newCurr->next;
        }
        return newHead;
    }
};