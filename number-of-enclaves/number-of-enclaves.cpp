class Solution {
public:
 void dfs(int row,int col,vector<vector<int>> &visited,vector<vector<int>> &grid,int dr[], int dc[], int m ,int n )
   {
      visited[row][col]=1;
      for(int i=0;i<4;i++)
      {
          int nrow =row+dr[i];
          int ncol= col+dc[i];
          if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol] && grid[nrow][ncol]==1 )
          dfs(nrow,ncol,visited,grid,dr,dc,m,n);
      }

   }
    int numEnclaves(vector<vector<int>>& grid) 
    {
        //calculate the total number of land cells 
        //calculate all those land cells connected with the boundary land cells


          int m= grid.size();//no. of rows 
       int n=grid[0].size(); //no. of columns 
       vector<vector<int>> visited(m, vector<int>(n, 0));
       int dr[]={-1,0,1,0}; 
       int dc[]={0,1,0,-1};
    //traverse  the first and end row 

    for(int i=0;i<n;i++)
    {   
        //if the element is 1 or a land cell and it has not been visited 
        //we will run dfs on it 
        
        if(grid[0][i]==1 && !visited[0][i])
        dfs(0,i,visited,grid,dr,dc,m,n);
        
        
        if(grid[m-1][i]==1 && !visited[m-1][i])
        dfs(m-1,i,visited,grid,dr,dc,m,n);
    }

    //first col and end col
    //we will skip the first element from the top and the end 
    for(int i=1;i<m-1;i++)
    {   
        //if the element is 1 and it has not been visited 
        //we will run dfs on it 
        if(grid[i][0]==1 && !visited[i][0])
        dfs(i,0,visited,grid,dr,dc,m,n);
        
        if(grid[i][n-1]==1 && !visited[i][n-1])
        dfs(i,n-1,visited,grid,dr,dc,m,n);
    }
    int landcells=0,boundarylandcells=0;
    for(int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            if(visited[i][j]==1)
            boundarylandcells++;

            if(grid[i][j]==1)
            landcells++;
        }
    }
       
        return landcells - boundarylandcells;
    }
};