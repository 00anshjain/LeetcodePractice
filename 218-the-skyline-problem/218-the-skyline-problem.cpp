class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& build) {
        vector<pair<int, int>> v;
        for(auto x : build)
        {
            int sp = x[0]; //startpoint
            int ep = x[1]; //endpoint
            int h = x[2];
            v.push_back({sp, -h}); //multiplied by negative so that we know its the strating height
            //Also me want maxm hieght of builiding so -ve sign will (in asceding order sort) will 
            // get the maxm height of buulding in front
            v.push_back({ep, h});
        }
        sort(v.begin(), v.end());
        // priority_queue<int> pq;
        multiset<int> st;
        vector<vector<int>> ans;
        st.insert(0);
        int currHt = 0;
        for(auto x : v)
        {
            if(x.second < 0) // we have a start point
            {
                st.insert(-x.second);
                int t = *(st.rbegin());
                if(t > currHt)
                {
                    ans.push_back({x.first, t});
                    currHt = t;
                }
            }
            else // removing an height
            {
                auto itr = st.find(x.second);
                st.erase(itr);
                // st.erase(x.second);
                int t = *(st.rbegin());
                if(currHt != t)
                {
                    currHt = t;
                    ans.push_back({x.first, currHt});
                }
            }
        }
        return ans;
    }
};