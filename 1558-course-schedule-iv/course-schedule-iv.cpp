class Solution {
public:

    bool dfs(vector<int> adj[],int src, int des,vector<int>& vis){
        vis[src] = 1;
        if(src == des) return true;
        if(adj[src].size() == 0) return false;
        
        for(auto neigh : adj[src]){
            if(!vis[neigh])
                if(dfs(adj, neigh, des, vis) == true) return true;
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> result;
        vector<int> adj[numCourses];
        for(auto edge : prerequisites){
            adj[edge[0]].push_back(edge[1]);
        }
        vector<int> vis(numCourses,0);
        for(auto query : queries){
            bool res = dfs(adj,query[0],query[1],vis);
            result.push_back(res);
            memset(vis.data(),0,vis.size() * sizeof(int));
        }
        return result;
    }
};