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
    // vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    //     int V = graph.size();
    //     vector<int> vis(V,0);
    //     vector<int> check(V,0);
    //     vector<int> safeNodes;

    //     for(int i=0;i<V;i++){
    //         if(!vis[i]){
    //             dfs(i, graph, vis,check);
    //         }
    //     }
        
    //     for(int i=0;i<V;i++){
    //         if(check[i] == 1){
    //             safeNodes.push_back(i);
    //         }
    //     }
    //     return safeNodes;
    // }
    vector<int> eventualSafeNodes(vector<vector<int>>& edges){
        int V = edges.size();
        vector<vector<int>> adjRev(V);
        for(int i=0;i<V;i++){
            //i -> it
            for(auto it : edges[i]){
                adjRev[it].push_back(i);
            }
        }
        
        //Increase Indegree
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it : adjRev[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> safenodes;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safenodes.push_back(node);

            for(auto it : adjRev[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(safenodes.begin(),safenodes.end());
        return safenodes;
    }
};