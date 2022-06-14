// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    struct Node{
	        char ch;
	        int freq;
	        Node* left;
	        Node* right;
	        Node(char ch, int freq)
	        {
	            this->ch = ch;
	            this->freq = freq;
	            left = NULL;
	            right = NULL;
	        }
	    };

        // static bool compare(Node* a, Node* b){
        //     return a.freq < b.freq;
        // }
        struct compare{
            bool operator()(Node* a, Node* b)
            {
                return a->freq > b->freq;
            }
        };
        void preorder(Node* root, vector<string> &ans, string s)
        {
            if(!root)
                return;
            // cout<<root->ch<<endl;
            if(root->ch != '$')
            {
                ans.push_back(s);
                return;
            }
            preorder(root->left, ans, s+'0');
            preorder(root->right, ans, s+'1');
        }
		vector<string> huffmanCodes(string s,vector<int> f,int n)
		{
		    priority_queue<Node*, vector<Node*>, compare> pq;
            // priority_queue<Node*, vector<Node*>, greater<int>()> pq;
            for(int i = 0; i < n; i++)
            {
                // Node* temp = new Node(s[i], f[i]);
                // pq.push(temp);
                pq.push(new Node(s[i], f[i]));
            }
            // cout<<pq.size()<<endl;
            while(pq.size() > 1)
            {
                Node* l = pq.top();
                pq.pop();
                Node* r = pq.top();
                pq.pop();
                Node* temp = new Node('$', l->freq + r->freq);
                temp->left = l;
                temp->right = r;
                pq.push(temp);
            }
            vector<string> ans;
            // Node* head = pq.top();
            preorder(pq.top(), ans, "");
            return ans;
		    // Code here
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}  // } Driver Code Ends