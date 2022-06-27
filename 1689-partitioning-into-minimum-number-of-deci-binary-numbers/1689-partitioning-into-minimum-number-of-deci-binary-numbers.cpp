class Solution {
public:
    int minPartitions(string n) {
        char c= '0';
        for(char x : n)
        {
            if(x > c)
            {
                c = x;
            }
        }
        return c - '0';
        
    }
};