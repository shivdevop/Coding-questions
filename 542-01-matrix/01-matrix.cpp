class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        //create a visited 2d matrix
        //create a distance 2d matrix 
           int m=mat.size();
           int n=mat[0].size();
          vector<vector<int>> visited(m, vector<int>(n, 0));
          vector<vector<int>> distance(m, vector<int>(n, 0));

         queue<pair<pair<int,int>,int>> q;//the first pair contains row and col no. and the second element contains the distance 
          int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
      

         for(int i=0;i<m;i++)
          {for(int j=0;j<n;j++)
            {
              if(mat[i][j]==0)
              {q.push({{i,j},0}); //pushing all the cells which have 0 initially 
                visited[i][j]=1;
              }           
            }
          } 
         
          while(!q.empty())
         {
          int r=q.front().first.first;
          int c=q.front().first.second;
          int dis=q.front().second;
          q.pop();
          distance[r][c]=dis;
          for(int i=0;i<4;i++)
          {
              int nrow=r+dr[i];
              int ncol=c+dc[i];
              if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && mat[nrow][ncol]==1 && visited[nrow][ncol]==0 )
              {
                  q.push({{nrow,ncol},dis+1});//pushing in the queue means visiting the cell
                  visited[nrow][ncol]=1;

              }
          }
         }
       
       return distance;
        
    }
};