class Solution {
public:
   bool dfsDetectCycle(int node,int visited[],int pathVisited[],vector<int> adj[],int safe[])
    {
        visited[node]=1;
        pathVisited[node]=1;
        
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                if(dfsDetectCycle(it,visited,pathVisited,adj,safe)==true)
                return true;
            }
            
            
            else if(pathVisited[it])
            return true;
        }
        safe[node]=1;
        pathVisited[node]=0;
        return false;
        
    }


    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
         int m=graph.size();
        vector<int> adj[m];
        for(int i=0;i<m;i++)
        {
            adj[i]=graph[i];
        }//creation of adjacency list


        //all the nodes of a cycle will not be safe states and all the noes which lead to a cycle will not be safe states.. rest all will be safe states


          int visited[m];
        int pathVisited[m];
        int safe[m];
        memset(visited,0,sizeof(visited));
         memset(pathVisited,0,sizeof(pathVisited));
          memset(safe,0,sizeof(safe));

        
        for(int i=0;i<m;i++)
        {
            if(!visited[i])
            {
                dfsDetectCycle(i,visited,pathVisited,adj,safe);//calling the dfs on every non visited node 
                
            }
        }//end of for
        
        vector<int> ans;

        for(int i=0;i<m;i++)
        {
            if(safe[i]==1)
            ans.push_back(i);
        }
      return ans;
    }
};