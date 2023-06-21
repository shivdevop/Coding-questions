class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {    
        if(grid[0][0]==1)
        return -1;
        //create a 2d distance vector 
        int m=grid.size(); //no. of rows 
        int n=grid[0].size();//no. of columns 
        
        const int INF=1e9;
        vector<vector<int>> dist(m,vector<int>(n,INF));
       dist[0][0]=1;

       priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;   
        pq.push({1,{0,0}}); //{dist,{row,col}}
        

        int dr[]={-1,-1,-1,0,0,1,1,1};//possible 8 combinations of change in row and col values 
        int dc[]={-1,0,1,-1,1,-1,0,1};

        while(!pq.empty())
        {
            auto it=pq.top();
            int d=it.first;
            int row=it.second.first;
            int col=it.second.second;
            pq.pop();
            
            for(int i=0;i<8;i++)
            {
                int newrow=row+dr[i];
                int newcol=col+dc[i];
                int newdist=d+1;
                
                if(newrow>=0 && newrow<m && newcol>=0 && newcol<n)
               { int adj_node=grid[newrow][newcol];
                if(adj_node==0 && newdist<dist[newrow][newcol])
                {
                    dist[newrow][newcol]=newdist;
                    pq.push({newdist,{newrow,newcol}});
                }
               }
            }

        }//end of while

        if(dist[m-1][n-1]==INF)
        return -1;
        else
        return dist[m-1][n-1];

    }
};