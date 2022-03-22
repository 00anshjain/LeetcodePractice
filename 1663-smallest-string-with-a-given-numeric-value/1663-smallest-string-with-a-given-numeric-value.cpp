class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        while(n > 0)
        {
            if(ceil(k/26.0) < n)
            {
                // cout<<"a "<<k<<" "<<n<<endl;
                ans += 'a';
                k--;
                n--;
            }
            else if(k % 26 > 0)
            {
                
                char c = 'a' + ((k%26) - 1);
                // cout<<"c "<<k<<" "<<n<<endl;
                ans += c;
                n--;
                k-= (k%26);
            }
            else// if(k/26.0 == n)
            {
                // cout<<"z "<<k<<" "<<n<<endl;
                ans += 'z';
                k-= 26;
                n--;
            }
            
        }
        return ans;
    }
};