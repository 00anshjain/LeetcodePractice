class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(auto& s : emails)
        {
            string g = "";
            bool atRate = false;
            int n = s.size();
            int i = 0;
            bool plusFound = false;
            // for(int i = 0; i < n; i++)
            while(s[i] != '@')
            {
                char c = s[i];
                if(plusFound)
                {
                    i++;
                    // continue;
                }
                else if(s[i] == '+')
                {
                    plusFound = true;
                    i++;
                }
                else if(s[i] == '.')
                {
                    i++;
                }
                else
                {
                    g += s[i++];
                }
            }
            // if(s[i] != '@')
            //     return -1;
            g += s.substr(i);//since s[i] is '@'
            // cout<<g<<endl;
            st.insert(g);
        }
        return st.size();
        
    }
};