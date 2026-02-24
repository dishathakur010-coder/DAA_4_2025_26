class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>> adj(V);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<bool> visited(V, false);
        priority_queue<pair<int,int>, 
                       vector<pair<int,int>>, 
                       greater<pair<int,int>>> pq;
        pq.push({0, 0});  
        int minCost = 0;
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int weight = top.first;
            int node = top.second;
            if(visited[node]) continue;
            visited[node] = true;
            minCost += weight;
            for(auto &nbr : adj[node]) {
                int adjNode = nbr.first;
                int adjWeight = nbr.second;
                if(!visited[adjNode]) {
                    pq.push({adjWeight, adjNode});
                }
            }
        }
        return minCost;
    }
};
