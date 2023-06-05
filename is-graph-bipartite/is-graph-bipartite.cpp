class Solution {
public:
    bool checkdfsoddcycle(int node,int color,int visited[],vector<int> adj[])
    {
        visited[node]=color;

        for(auto it:adj[node])
        {
            if(visited[it]==-1)
          {  if(checkdfsoddcycle(it,!color,visited,adj)==true)
            return true;
          }
            else if(visited[it]==visited[node])
            return true;
        }


      return false;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {   int m=graph.size();
        vector<int> adj[m];
        for(int i=0;i<m;i++)
        {
            adj[i]=graph[i];
        }//craetion of adjacency list

        int visited[m];
        for(int i=0;i<m;i++)
        visited[i]=-1;

        for(int i=0;i<m;i++)
        {
            if(visited[i]==-1)
            {
                if(checkdfsoddcycle(i,0,visited,adj)==true)
                 return false;
            }
        }
    return true;
    }
};