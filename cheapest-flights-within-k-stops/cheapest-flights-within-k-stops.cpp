class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {       int m=flights.size(); //no. of rows 
        // int n=flights[0].size();//no. of columns 

        //creation of adjacency list
        vector<pair<int,int>> adj[n]; 
        for(int i=0;i<m;i++)
        {
          int node=flights[i][0];
          int neighbour=flights[i][1];
          int price=flights[i][2];
          adj[node].push_back({neighbour,price});
        }
      
       const int INF = 1e9; 
       vector<int> price(n,INF);
       price[src]=0;
       
       queue<vector<int>> pq; 
       pq.push({0,src,0});
    
    
      while (!pq.empty()) {
    auto curr = pq.front();
    int stops = curr[0];
    int node = curr[1];
    int cost = curr[2];
    pq.pop();
 
     if(stops>k)
     continue;
    
    // if (node == dst) { // Break the loop if the destination is reached
    //     break;
    // }

    for (auto neighbor : adj[node]) { // Changed variable name from "it" to "neighbor"
        int adjNode = neighbor.first;
        int ticketCost2 = neighbor.second;
        int newCost = cost + ticketCost2;

        if (stops <=k && newCost < price[adjNode]) { // Fixed condition from "<" to "<="
            price[adjNode] = newCost;
            pq.push({stops+1, adjNode,newCost});
        }
    }
}
       if(price[dst]==INF)
       return -1;
       else 
       return price[dst];
       
        
    }
};