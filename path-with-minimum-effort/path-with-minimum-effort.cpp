class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
          int m=heights.size(); //no. of rows 
        int n=heights[0].size();//no. of columns 
        
        const int INF=1e9;
        vector<vector<int>> effort(m,vector<int>(n,INF));
       effort[0][0]=0;

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;   //min heap

         pq.push({0,{0,0}}); //{dist,{row,col}}
        
          int dr[]={-1,0,1,0};
          int dc[]={0,-1,0,1};


          while(!pq.empty())
          {
            auto it=pq.top();
            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;
            pq.pop();
            if(row==m-1 && col==n-1)
            return diff;

             for(int i=0;i<4;i++)
            {
                int newrow=row+dr[i];
                int newcol=col+dc[i];
                
               
                
                if(newrow>=0 && newrow<m && newcol>=0 && newcol<n)
               { 
                    int newEffort=max(abs(heights[newrow][newcol]-heights[row][col]),diff);
                      if(newEffort<effort[newrow][newcol])
                      {
                        pq.push({newEffort,{newrow,newcol }});
                        effort[newrow][newcol]=newEffort;

                      }
                     
                  
                }
               }
            }//end of while
       

          return -1;


      
          }



};