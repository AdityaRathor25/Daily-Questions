// You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

// Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

// Example 1:


// Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
// Output: 3
// Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
// Example 2:


// Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
// Output: 0
// Explanation: All 1s are either on the boundary or can reach the boundary.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 500
// grid[i][j] is either 0 or 1.



#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j] == 1 ){
            return true;
        }
        return false;
    }
    
    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid){
        grid[i][j] = 0;
        
        int ax[4] = {1, -1, 0, 0};
        int ay[4] = {0, 0, 1, -1};
        
        for(int k=0; k<4; k++){
            int nx = i + ax[k];
            int ny = j + ay[k];
            
            if(isValid(nx,ny, n, m, grid)){
                dfs(nx, ny, n, m, grid);
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0 ; j<m ; j++)
            {
                if(i*j ==0 || i==n-1 || j==m-1 )
                {
                    if(grid[i][j]==1)
                        dfs(i,j,n,m,grid);
                }
            }
        }
        int count=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(grid[i][j]==1)
                 count++;
            }
        }
        return count;
    }