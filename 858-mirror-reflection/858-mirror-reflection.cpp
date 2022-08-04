class Solution {
public:
    int mirrorReflection(int p, int q) {
        int x = 0, y = 0;
        int qdir = 1, pdir = 1;//going up;
        while(1)
        {
            x += pdir*p;
            y += qdir*q;
            pdir = -1*pdir;
            while(y > p||y < 0)
            {
                if(y > p)
                {
                    y = p - (y-p);
                    qdir = -1;
                }
                else if(y < 0)
                {
                    y = -1*y;
                    qdir = 1;
                }
            }
            // cout<<x<<" "<<y<<endl;
            if(x == 0 && y == p)
                return 2;
            else if(x == p && y == 0)
                return 0;
            else if(x == p && y == p)
                return 1;
        }
        return -1;
    }
};