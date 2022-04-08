// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find a solved Sudoku.
    bool isSafe(int grid[N][N], int i, int j)
    {
        for(int k = 0; k < N; k ++)
        {
            if(grid[i][k] == grid[i][j] && k != j)
                return false;
            if(grid[k][j] == grid[i][j] && k != i)
                return false;
        }
        for(int x = (i/3)*3; x<= (i/3)*3 + 2; x++)
        {
            for(int y = (j/3)*3; y<= (j/3)*3 + 2; y++)
            {
                if(x == i && y == j)
                    continue;
                if(grid[x][y] == grid[i][j])
                    return false;
            }
        }
        return true;
    }
    bool solver(int grid[N][N], int i, int j)
    {
        if(j == N)
        {
            i++;
            j = 0;
        }
        if(i == N && j == 0)
            return true;
        // bool a;
        if(grid[i][j] != 0)
        {
            if(isSafe(grid, i, j))
                return solver(grid, i, j+1);
            //         return true;
            // return false;
        }
        for(int k = 1; k <= N; k++)
        {
            grid[i][j] = k;
            if(isSafe(grid, i, j))
                if(solver(grid, i, j+1))
                    return true;
            grid[i][j] = 0;
        }
        return false;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
      return solver(grid, 0, 0);
            // printGrid(grid);
        // return true;
        // Your code here
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                cout<<grid[i][j]<<" ";
            }
            // cout<<endl;
        }
        // Your code here 
    }
};


// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends