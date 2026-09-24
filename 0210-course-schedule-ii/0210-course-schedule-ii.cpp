class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        // if(pre.size()<1) return {0};
        vector<vector<int>> adj(n);
        for(auto it:pre){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }
        //Now perform the Kahn's Algo
        vector<int> indegree(n);
        for(int i=0;i<n;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        // int topoIt = 0;
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            // topoIt++;
            topo.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(topo.size()==n) return topo;
        return {};
    }
};