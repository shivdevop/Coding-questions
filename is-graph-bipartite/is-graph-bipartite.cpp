class Solution {
public:
    bool checkdfsoddcycle(int node,int color,int visited[],vector<int> adj[])
    {
        visited[node]=color;

        for(auto it:adj[node])
        {
            if(visited[it]==-1)
          {  if(checkdfsoddcycle(it,!color,visited,adj)==false)
            return false;//this is a very important step that if any of the dfs calls says that yes there exists a odd length cycle or we cant color encode with just two colors such that no nearby nodes hasve the same color  then it cant be bipartite 
          }
            else if(visited[it]==visited[node])
            return false;
        }


      return true;
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
                if(checkdfsoddcycle(i,0,visited,adj)==false)
                 return false;
            }
        }
    return true;
    }
};