class Solution{
  public:
    vector<int> parent, rank;
    int findParent(int node){
        if(parent[node]==node)
            return node;
        return parent[node]=findParent(parent[node]); 
    }
    void unionSet(int u, int v){
        u=findParent(u);
        v=findParent(v);
        if(u==v) return;
        if(rank[u]<rank[v]){
            parent[u]=v;
        }
        else if(rank[v]<rank[u]){
            parent[v]=u;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
    int kruskalsMST(int V, vector<vector<int>> &edges){
        sort(edges.begin(), edges.end(), 
            [](vector<int> &a, vector<int> &b){
                return a[2] < b[2];
            });
        parent.resize(V);
        rank.resize(V,0);
        for(int i=0;i<V;i++)
            parent[i]=i;
        int mstWeight=0;
        for(auto &edge:edges) {
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            if(findParent(u)!=findParent(v)){
                mstWeight+=w;
                unionSet(u, v);
            }
        }
        return mstWeight;
    }
};
