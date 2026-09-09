class Solution {
private:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis,vector<int> &check){
        vis[node] = 2;

        for(auto it:adj[node]){
            if(vis[it]==0){
                if(dfs(it,adj,vis,check) == true) return true;
            }
            else if(vis[it] == 2){
                return true;
            }
        }
        check[node] = 1;
        vis[node] = 1;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // vector<vector<int>> adj(V);
        // for(auto edge : edges){
        //     int u = edge[0];
        //     int v = edge[1];
        //     adj[u].push_back(v);
        // }
        int V = graph.size();
        vector<int> vis(V,0);
        vector<int> check(V,0);
        vector<int> safeNodes;

        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, graph, vis,check);
            }
        }
        
        for(int i=0;i<V;i++){
            if(check[i] == 1){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};