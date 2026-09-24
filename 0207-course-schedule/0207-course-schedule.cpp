class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for(auto it:pre){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
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
        int topoIt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topoIt++;
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return topoIt == n;
    }
};