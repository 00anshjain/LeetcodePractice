class TrieNode{
    public: 
    bool isEnd;
    TrieNode* next[26];
    TrieNode()
    {
        isEnd = false;
        for(int i = 0; i < 26; i++)
            next[i] = NULL;
        // next = vector<TrieNode*>(26, NULL); 
    }
};
class Solution {
public:  
    int n, m;
    void insertInTrie(TrieNode* root, string &s)
    {
        for(auto c : s)
        {
            if(!root->next[c-'a'])
                root->next[c-'a'] = new TrieNode;
            root = root->next[c-'a'];
        }
        root->isEnd = true;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(auto x : words)
            insertInTrie(root, x);
        unordered_set<string> foundWords;
        goFind(board, root, foundWords);
        vector<string> ans(foundWords.begin(), foundWords.end());
        return ans;
    }
    void goFind(vector<vector<char>>& board, TrieNode* root, unordered_set<string>& foundWords)
    {
        n = board.size();
        m = board[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(root->next[board[i][j] -'a'])
                {
                    string word = "";
                    letsStart(board, root, i, j, foundWords, word);
                }
            }
        }
    }
    void letsStart(vector<vector<char>>& board, TrieNode* root, int r, int c, unordered_set<string> &foundWords, string &word)
    {
        if(r >= n || c >= m || r < 0 || c < 0 || board[r][c] == ' ')
            return;
        if(!root->next[board[r][c] - 'a'])
            return;
        word.push_back(board[r][c]);
        root = root->next[board[r][c] - 'a'];
        if(root->isEnd)
            foundWords.insert(word);
        char ch = board[r][c];
        board[r][c] = ' ';
        letsStart(board, root, r-1, c, foundWords, word);
        letsStart(board, root, r+1, c, foundWords, word);
        letsStart(board, root, r, c-1, foundWords, word);
        letsStart(board, root, r, c+1, foundWords, word);
        word.pop_back();
        board[r][c] = ch;
        return;
    }
};