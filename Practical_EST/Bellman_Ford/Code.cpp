#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        const int INF = 1e8;
        vector<int> dist(V, INF);
        dist[src] = 0;
        for (int i = 0; i < V - 1; i++) {
            for (auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                if (dist[u] != INF &&
                    dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }       
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (dist[u] != INF &&
                dist[u] + w < dist[v]) {
                return {-1}; 
            }
        }

        return dist;
    }
};
