// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        sort(arr, arr+n);
        string s1 = "", s2 = "";
        bool turn = false;
        for(int i = 0; i < n; i++)
        {
            if(!turn)
                s1 += (to_string(arr[i]));
            else
                s2 += (to_string(arr[i]));
            turn = !turn;
        }
        // cout<<s1<<" "<<s2<<endl;
        int n1 = s1.size();
        int n2 = s2.size();
        string ans =  "";
        int carry = 0;
        while(n1 > 0 && n2 > 0)
        {
            int a = s1[n1-1] - '0' + s2[n2-1] - '0' + carry;
            ans += (to_string(a%10));
            if(a >= 10)
                carry = 1;
            else
                carry = 0;
            n1--;
            n2--;
        }
        while(n1 > 0)
        {
            int a = s1[n1-1] - '0' + carry;
            ans += (to_string(a%10));
            if(a >= 10)
                carry = 1;
            else
                carry = 0;
            n1--;
        }
        while(n2 > 0)
        {
            int a = s2[n2-1] - '0' + carry;
            ans += (to_string(a%10));
            if(a >= 10)
                carry = 1;
            else
                carry = 0;
            n2--;
        }
        while(ans.size() > 0 && ans.back() == '0')
            ans.pop_back();

        if(carry > 0)
            ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
        
        // code here
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends