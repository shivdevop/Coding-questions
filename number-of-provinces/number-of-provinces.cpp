class Solution {
public:
    void dfs( int node,vector<int> adj[], int visited[] )
    {
        visited[node]=1;
        for(int i=0;i<adj[node].size();i++)
        {   
            if(visited[adj[node][i]]==0)
            dfs(adj[node][i], adj , visited );
        }
      
    //   for(auto it:adj[node])
    //   {
    //       if(!visited[it])
    //       dfs(it,adj,visited);
    //   }
    }
   
   
    int findCircleNum(vector<vector<int>>& isConnected) 
    {  
         //what we can simply do is we can create an adjacency list 
          int n=isConnected.size();
          vector<int> adj[n];
          
          for(int i=0;i<n;i++)
          {for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {adj[i].push_back(j);
                adj[j].push_back(i);
                }//i and j both have an edge in between 
            }
          }//adjacency list created

        
        int visited[n];
        memset(visited, 0, sizeof(visited));
        //how you can initialize an array 
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                count++;
                dfs(i,adj,visited);
            }
        }//end of for
     
     return count;
    }
};