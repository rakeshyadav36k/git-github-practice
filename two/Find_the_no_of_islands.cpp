/*
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). 
Find the number of islands.

Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., 
in all 8 directions.
*/


class Solution {
  public:
    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>> &vis){
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int delrow=-1;delrow<=1;delrow++)
            {
                for(int delcol=-1;delcol<=1;delcol++)
                {
                    int nrow=row+delrow;
                    int ncol=col+delcol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
    
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(!vis[row][col] && grid[row][col]=='1')
                {
                    count++;
                    bfs(row,col,grid,vis);
                }
            }
        }
        return count;
    }
};