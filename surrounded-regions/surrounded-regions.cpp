class Solution {
public:
   void dfs(int row,int col,vector<vector<int>> &visited,vector<vector<char>> &board,int dr[], int dc[], int m ,int n )
   {
      visited[row][col]=1;
      for(int i=0;i<4;i++)
      {
          int nrow =row+dr[i];
          int ncol= col+dc[i];
          if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol] && board[nrow][ncol]=='O' )
          dfs(nrow,ncol,visited,board,dr,dc,m,n);
      }

   }
   
   
    void solve(vector<vector<char>>& board) 
    {  
       int m= board.size();//no. of rows 
       int n=board[0].size(); //no. of columns 
       vector<vector<int>> visited(m, vector<int>(n, 0));
       int dr[]={-1,0,1,0}; 
       int dc[]={0,1,0,-1};
    //traverse  the first and end row 

    for(int i=0;i<n;i++)
    {   
        //if the element is O and it has not been visited 
        //we will run dfs on it 
        
        if(board[0][i]=='O' && !visited[0][i])
        dfs(0,i,visited,board,dr,dc,m,n);
        
        
        if(board[m-1][i]=='O' && !visited[m-1][i])
        dfs(m-1,i,visited,board,dr,dc,m,n);
    }

    //first col and end col
    //we will skip the first element from the top and the end 
    for(int i=1;i<m-1;i++)
    {   
        //if the element is O and it has not been visited 
        //we will run dfs on it 
        if(board[i][0]=='O' && !visited[i][0])
        dfs(i,0,visited,board,dr,dc,m,n);
        
        if(board[i][n-1]=='O' && !visited[i][n-1])
        dfs(i,n-1,visited,board,dr,dc,m,n);
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!visited[i][j] && board[i][j]=='O')
            board[i][j]='X';
        }
    }

  }
};