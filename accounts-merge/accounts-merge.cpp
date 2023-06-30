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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
         int m=accounts.size();
         disjoint_Set ds(m);

        //we can first use a map to store all strings and the name they belong as key value pairs 
        //the key/string which already appears in the map we will store the entire node as the child of the value of the string which was pushed earlier into map

        map<string,int> mpp;

        for(int i=0;i<accounts.size();i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(mpp.find(accounts[i][j])!=mpp.end())
                {
                    int u=mpp[accounts[i][j]];
                    ds.union_by_size(u,i);
                }
                else
                mpp[accounts[i][j]]=i;

            }
        }


        vector<vector<string>> mergedmail(m); 
        
        for(auto pair:mpp)
        {
            string mail=pair.first;
            int mail_parent=ds.find_parent(pair.second);
            mergedmail[mail_parent].push_back(mail);
        }

        
        vector<vector<string>> ans;
        for(int i=0;i<m;i++)
        {       if(mergedmail[i].size()==0)
                continue;
                sort(mergedmail[i].begin(),mergedmail[i].end());
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                temp.insert(temp.end(),mergedmail[i].begin(),mergedmail[i].end());

                ans.push_back(temp);
           

        }
    return ans;
        
    }
};