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
	      Node(Node* l, Node* r)
	      {
	          ch = '$';
	          freq = l->freq + r->freq;
	          left = l;
	          right = r;
	      }
	    };
	    struct compare{
	        bool operator()(Node* l, Node* r)
	        {
	            return l->freq > r->freq;
	        }
	    };
	    void inorder(Node* root, vector<string> &s, string curr)
	    {
	        if(!root)
	            return;
	        if(root->ch != '$')
	        {
	            s.push_back(curr);
	            return;
	        }
	        inorder(root->left, s, curr + '0');
	        inorder(root->right, s, curr + '1');
	        
	    }
		vector<string> huffmanCodes(string S,vector<int> f,int n)
		{
		    priority_queue<Node*, vector<Node*>, compare> pq;
		    for(int i = 0; i < n; i++)
		    {
		        pq.push(new Node(S[i], f[i]));
		    }
		    while(pq.size() > 1)
		    {
		        Node* l = pq.top();
		        pq.pop();
		        Node* r = pq.top();
		        pq.pop();
		        Node* node = new Node(l,r);
		        pq.push(node);
		    }
		    string curr = "";
		    vector<string> s;
		    inorder(pq.top(), s, curr);
		    return s;
		    
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