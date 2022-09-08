class Solution {
public:
    bool check(string &s, unordered_map<char, char>& left, unordered_map<char, char>& right, unordered_map<char, pair<int, int>> &go)
    {
        int x = 0, y = 0;
        char dir = 'N';//north
        for(auto c : s)
        {
            if(c == 'G')
            {
                x += go[dir].first;
                y += go[dir].second;
            }
            else if(c == 'L')
                dir = left[dir];
            else
                dir = right[dir];
        }
        return (x == 0 && y == 0) || dir != 'N';
    }
    bool isRobotBounded(string s) {
        unordered_map<char, char> left, right;
        unordered_map<char, pair<int, int>> go;
        go['N'] = {0, 1}; go['E'] = {-1, 0}; go['S'] = {0, -1}; go['W'] = {1, 0};
        left['N'] = 'W'; left['W'] = 'S'; left['S'] = 'E'; left['E'] = 'N';
        right['N'] = 'E'; right['E'] = 'S'; right['S'] = 'W'; right['W'] = 'N';
        // string s2 = s + s;
        // string s3 = s2 + s;
        // string s4 = s3 + s;
        // for(int i = 0; i < 4; i++)
        // {
        // if(check(s, left, right, go) || check(s2, left, right, go) || check(s3, left, right, go) || check(s4, left, right, go))
        if(check(s, left, right, go))
            return true;
        return false;    
            
        // }
        
        
        
    }
};