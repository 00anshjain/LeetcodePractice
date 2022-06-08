class Solution {
public:
    int distributeCandies(vector<int>& candy) {
        unordered_set<int> st(candy.begin(), candy.end());
        return min((candy.size() +1 )/2, st.size());
    }
};