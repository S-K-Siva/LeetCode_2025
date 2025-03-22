class Solution {
public:
    int timer = 0;
    void dfs(int node, int parent, vector<vector<int>>& adj,vector<int>& low, vector<int>& tin,
    vector<int>& vis,vector<vector<int>>& result){
        vis[node] = 1;
        low[node] = tin[node] = timer;
        ++timer;
        for(auto neigh : adj[node]){
            if(neigh == parent) continue;
            if(!vis[neigh]){
                
                dfs(neigh,node,adj,low,tin,vis,result);
                low[node] = min(low[node],low[neigh]);
                if(low[neigh] > tin[node]){
                    result.push_back({neigh,node});
                }
                
            }else{
                low[node] = min(low[node],low[neigh]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> result;
        vector<int> low(n),tin(n),vis(n);
        vector<vector<int>> adj(n,vector<int>());
        for(auto edge : connections){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(0,-1,adj,low,tin,vis,result);
        return result;
    }
};