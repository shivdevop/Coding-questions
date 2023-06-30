class disjoint_Set
{ 
    
   
    public:
    vector<int> rank,parent,size;
    disjoint_Set(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<n+1;i++)
        parent[i]=i;

        size.resize(n+1,1);
    }
    
    int find_parent(int u)
    {
        if(parent[u]==u)
        return u;
        return parent[u]=find_parent(parent[u]);
    }

    void union_by_size(int u,int v)
    {
        int u_up=find_parent(u);//ultimate parent of u 
        int v_up=find_parent(v);
        
        if(v_up==u_up)
        return;
        if(size[v_up]<size[u_up])
        {
            parent[v_up]=u_up;
            size[u_up]+=size[v_up];
        }
        else
        {
                 parent[u_up]=v_up;
            size[v_up]+=size[u_up];
        }
        
    }
};



class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) 
     {
     disjoint_Set ds(n); //we have created disjoint set , now lets establish union relationships
    int extraedges=0;
    int edges=connections.size(); 
    for(int i=0;i<edges;i++)
    {
        
            int u=connections[i][0];
            int v=connections[i][1];
            int u_up=ds.find_parent(u);
            int v_up=ds.find_parent(v);


            if(u_up!=v_up)
            ds.union_by_size(u,v);
            else 
            extraedges++;
        
    }
   int components=0;
    for (int i=0;i<n;i++)
    {
        if(ds.find_parent(i)==i)
        components++;
    }
     
     int ans=components-1;
    if(extraedges>=ans)
    return ans;
    else
    return -1;

     }
};
























