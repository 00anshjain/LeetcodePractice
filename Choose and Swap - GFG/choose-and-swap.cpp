// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string s){
        // int arr[26];
        // memset(arr, INT_MAX, sizeof(arr));
        vector<int> arr(26, INT_MAX);
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            if(arr[s[i] - 'a'] == INT_MAX)
                arr[s[i] - 'a'] = i;
        }
        // for(int i = 0; i < 26; i++)
        //     cout<<arr[i]<<" ";
        // cout<<endl;
        int mx = -1;
        int mnError = INT_MAX;
        int ch1 = 0, ch2 = 0;
        for(int i = 0; i < 26; i++)
        {
            if(arr[i] == INT_MAX)
                continue;
            if(arr[i] > mx)
            {
                mx = arr[i];
                continue;
            }
            else
            {
                if(arr[i] > mnError)
                    continue;
                mnError = arr[i];
                for(int j = 0; j < i; j++)
                {
                    if(arr[j] == INT_MAX)
                        continue;
                    // cout<<"i = "<<i<<" j ="<<j<<endl;
                    if(arr[j] > arr[i])
                    {
                        ch1 = j+'a';
                        ch2 = i+'a';
                        // cout<<ch1<<" "<<ch2<<endl;
                        break;
                    }
                }
            }
        }
        if(ch1 == ch2)
            return s;
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == ch1)
                s[i] = ch2;
            else if(s[i] == ch2)
                s[i] = ch1;
        }
        return s;
        
        
        // Code Here
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends