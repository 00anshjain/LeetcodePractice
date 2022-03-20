class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottom) {
        int num1 = tops[0];
        int num2 = bottom[0];
        int top1 = 0, btm1 = 0;
        int top2 = 0, btm2 = 0;
        int n = tops.size();
        for(int i = 0; i < n; i++)
        {
            if(num1 != -1 && tops[i] == num1)
            {
                btm1++;
            }
            else if(num1 != -1 && bottom[i] == num1)
            {
                top1++;
            }
            else
                num1 = -1;
            if(tops[i] == num1 && bottom[i] == num1)
               btm1--; 
            // if(top[i] && )
            if(num2 != -1 && tops[i] == num2)
            {
                btm2++;
            }
            else if(num2 != -1 && bottom[i] == num2)
            {
                top2++;
            }
            else
                num2 = -1;
            if(tops[i] == num2 && bottom[i] == num2)
               btm2--;
            if(num1 == -1 && num2 == -1)
                return -1;
        }
        int ans = INT_MAX;
        if(num1 != -1)
        {
            ans  = min(top1, btm1);
        }
        // cout<<num1<<top1<<endl<<btm1<<endl<<"num2 = "<<num2<<endl<<top2<<endl<<btm2;
        if(num2 != -1)
        {
            ans = min(min(ans, btm2), top2);
        }
        return ans;
        
        
    }
};