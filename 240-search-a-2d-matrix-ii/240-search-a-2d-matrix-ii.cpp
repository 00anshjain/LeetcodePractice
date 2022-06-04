class Solution {
public:
    bool binarySearch(vector<vector<int>> &matrix, int i, int n, int m, int target)
    {
        int left = 0, right = n-1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(matrix[mid][i] == target)
                return true;
            else if(matrix[mid][i] < target)
                left = mid +1;
            else
                right = mid - 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        //for selecting colums, we cut down columns by using first and last row
        int r = upper_bound(matrix[0].begin(), matrix[0].end(), target) - matrix[0].begin();
        int l = lower_bound(matrix[n-1].begin(), matrix[n-1].end(), target) - matrix[n-1].begin();
        
        for(int i = l; i < r; i++)
        {
            if(binarySearch(matrix, i, n, m, target))
                return true;
            // int k = lower_bound(matrix[0][i].begin(), matrix[].end(), target) - matrix[i].begin();
        }
        return false;
    }
};