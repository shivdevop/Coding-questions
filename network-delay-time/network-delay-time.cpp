class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        int m=times.size();
        // int n=times[0].size();
        
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<m;i++)
        {
            int node=times[i][0];
            int adjnode=times[i][1];
            int time=times[i][2];
            adj[node].push_back({adjnode,time});
        }

        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;   //min heap

        pq.push({0,k});  //{time taken to reach a node, that node}



        const int INF=1e9;
        vector<int> timeVector(n+1,INF);
        timeVector[k]=0;

        while(!pq.empty())
        {
            auto x=pq.top();
            int timetaken=x.first;
            int node=x.second;
            pq.pop();

            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int time=it.second;
                int newtime=timetaken + time;

                if(newtime<timeVector[adjnode])
                {
                    pq.push({newtime,adjnode});
                    timeVector[adjnode]=newtime;
                }
            }
        }
        int mini=timeVector[1];
        
        for( int i=1;i<n+1;i++)
        {
            if(timeVector[i]==INF)
            return -1;
            else
            mini=max(mini,timeVector[i]);

        }
        return mini;
    }
};