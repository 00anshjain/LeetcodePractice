class Solution {
public:
    int leftbinarySearch(vector<string>& products, int left, int right, string &w)
    {
        int ans = right + 1;
        while(left <= right)
        {
            int mid = (left + right)/2;
            int res = w.compare(products[mid].substr(0, w.size()));
            if(res == 0)
            {
                ans = mid;
                right = mid - 1;// we go on searching left
            }
            else if(res < 0) // w is lexographically smaller i.e. the other string is bigger we shift left side
            {
                right = mid - 1;
            }
            else if(res > 0)
            {
                left = mid + 1;
            }
        }
        return ans;
    }
    int rightbinarySearch(vector<string>& products, int left, int right, string &w)
    {
        int ans = left - 1;
        while(left <= right)
        {
            int mid = (left + right)/2;
            int res = w.compare(products[mid].substr(0, w.size()));
            if(res == 0)
            {
                ans = mid;
                left = mid + 1;// we go on searching left
            }
            else if(res < 0) // w is lexographically smaller i.e. the other string is bigger we shift left side
            {
                right = mid - 1;
            }
            else if(res > 0)
            {
                left = mid + 1;
            }
        }
        return ans;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        // vector<>
        int n = searchWord.size();
        int left = 0, right = products.size() - 1;
        string w = "";
        for(int i = 0; i < n; i++)
        {
            w += searchWord[i];
            vector<string> suggestion;
            left = leftbinarySearch(products, left, right, w);
            right = rightbinarySearch(products, left, right, w);
            // cout<<w<<" "<<left<<" "<<right<<endl;
            // vector<int> suggestion;
            for(int k = left, cnt = 0; k <= right && cnt < 3; k++, cnt++)
            {
                suggestion.push_back(products[k]);
            }
            res.push_back(suggestion);
        }
        return res;
    }
};