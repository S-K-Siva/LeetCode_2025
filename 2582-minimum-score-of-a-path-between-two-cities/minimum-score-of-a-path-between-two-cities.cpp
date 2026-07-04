class Solution {
public:
    void dfs(int& result, vector<bool>& visited, vector<vector<pair<int,int>>>& adjLst, int node){
        visited[node] = true;
        for(auto it : adjLst[node]){
            result = min(result, it.second);
            if(!visited[it.first]){
                dfs(result, visited, adjLst, it.first);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adjLst(n+1);
        for(auto it : roads){
            adjLst[it[0]].push_back({it[1],it[2]});
            adjLst[it[1]].push_back({it[0],it[2]});
        }
        vector<bool> visited(n+1,false);
        int result = INT_MAX;
        dfs(result, visited, adjLst, 1);
        return result;
    }
};