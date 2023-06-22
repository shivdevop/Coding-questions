class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {   
         
         int m=edges.size();
         vector<vector<int>> dist(n,vector<int>(n,1e9));
       
         for(int i=0;i<m;i++)
         {
            int u=edges[i][0];
            int v=edges[i][1];
            int edgewt=edges[i][2];

            dist[u][v]=edgewt;
            dist[v][u]=edgewt;
         }  
          //adjacency matrix created 
           for(int i=0;i<n;i++)
	    {
            for(int j=0;j<n;j++)
	    {
	        if(i==j)
	        dist[i][j]=0;
	        
	    }
	    }
        //adjacency matrix created
         
         //now we can travel via different nodes and also keep in mind the distance threshold to update the dist matrix 
          for(int via=0;via<n;via++)
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
                    //  int newdist=edges[i][via] + edges[via][j];
	                if(dist[i][via] + dist[via][j]<=distanceThreshold  &&  dist[i][via] + dist[via][j]<dist[i][j])
	            dist[i][j]=dist[i][via] + dist[via][j];
	            }
	        }
	    }
        //distance matrix updated
        
        int ansnode=-1,anscount=INT_MAX;

        for(int i=0;i<n;i++)
        {   int count=0;
            for(int j=0;j<n;j++)
            {
               if(dist[i][j]<=distanceThreshold && i!=j)
               count++;
            }
            if(count<anscount)
            {
                anscount=count;
                ansnode=i;
            }
            else if(count==anscount)
            ansnode=i;
        }
	    
    return ansnode;
    }
};