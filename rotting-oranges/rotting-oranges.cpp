class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
     //we need a visited matrix to keep update of the rotten oranges
     vector<vector<int>> visited = grid  ;
     queue<pair<pair<int,int>,int>> q;
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
        int m=grid.size();
        int n=grid[0].size();
        int max_time=0;
        //how to know where to start from
        //there is no other way except to traverse and figure out 
        for(int i=0;i<m;i++)
        {for(int j=0;j<n;j++)
          {
              if(grid[i][j]==2)
            {  q.push({{i,j},0});
            //   visited[i][j]=2;
            }
          }
        } 
     
      while(!q.empty())
      {
          int r=q.front().first.first;
          int c=q.front().first.second;
          int t=q.front().second;
          q.pop();
          max_time=max(max_time,t);
          for(int i=0;i<4;i++)
          {
              int nrow=r+dr[i];
              int ncol=c+dc[i];
              if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1 && visited[nrow][ncol]!=2 )
              {
                  q.push({{nrow,ncol},t+1});//pushing in the queue means visiting the cell
                  visited[nrow][ncol]=2;

              }
          }

      }//end of while



     for(int i=0;i<m;i++)
     {
         for(int j=0;j<n;j++)
         {   
             // if(visited[i][j]!=2 && visited[i][j]==1)
             //i can use the above if condition also but it doesnt make sense as i initially initialized the entire visited matrix with the grid matrix so i just need to make sure that no 1(or fresh oranges) are left 
             if( visited[i][j]==1)
             return -1;
         }
     }

         return max_time;
    }
};