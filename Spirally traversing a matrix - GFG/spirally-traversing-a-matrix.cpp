// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > arr, int n, int m) 
    {
        int i = 0;
    	int j = 0;
    	vector<int> ans;
    	bool flag = true;
    	while(flag)
    	{
    		flag = false;
    		int x = i, y = j;
    		if(arr[i][j] == -1)
    		{
    		    break;
    		  //  i++;
    		  //  j++;
    		  //  continue;
    		}
    		
    // 		cout<<x<<"  "<<y<<endl;
    		while(y <  m - i)
    		{
    		  //  cout<<"In"<<endl;
    		    if(arr[x][y] == -1)
    		        break;
    			flag = true;
    // 			cout<<arr[x][y]<<", ";
    			ans.push_back(arr[x][y]);
    			arr[x][y] = -1;
    			y++;
    		}
    		if(n == 1)
    		    break;
    		// y = m - i;
    		y--;
    		x++;
    		while(x <  n - i)
    		{
    		    if(arr[x][y] == -1)
    		        break;
    			flag = true;
    // 			cout<<arr[x][y]<<", ";
                ans.push_back(arr[x][y]);
    			arr[x][y] = -1;
    			x++;
    		}
    		x--;
    		y--;
    		while(y >= j)
    		{
    		    if(arr[x][y] == -1)
    		        break;
    			flag = true;
    // 			cout<<arr[x][y]<<", ";
    			ans.push_back(arr[x][y]);
    			arr[x][y] = -1;
    			y--;
    		}
    		y++;
    		x--;
    		while(x > i)
    		{
    		    if(arr[x][y] == -1)
    		        break;
    			flag = true;
    // 			cout<<arr[x][y]<<", ";
    			ans.push_back(arr[x][y]);
    			arr[x][y] = -1;
    			x--;
    		}
    		i++;
    		j++;
    	}
    	return ans;
    // 	cout<<"END"<<endl;
            // code here 
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends