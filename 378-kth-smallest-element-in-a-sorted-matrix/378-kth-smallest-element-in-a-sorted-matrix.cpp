class Solution {
public:
    vector<int> merge(vector<int> &v1, vector<int> &v2)
    {
        int n1 = v1.size(); int n2 = v2.size();
        vector<int> temp;
        int i = 0, j = 0;
        while(i < n1 && j < n2)
        {
            if(v1[i] < v2[j])
                temp.push_back(v1[i++]);
            else
                temp.push_back(v2[j++]);
        }
        while(i < n1)
            temp.push_back(v1[i++]);
        while(j < n2)
            temp.push_back(v2[j++]);
        return temp;
        
    }
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        while(n > 1)
        {
            for(int i = 0; i < n/2; i++)
            {
                mat[i] = merge(mat[i], mat[n-i-1]);
            }
            n = (n+1)/2;
        }
        return mat[0][k-1];
    }
};