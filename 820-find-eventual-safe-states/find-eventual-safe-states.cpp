class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        set<int> result;
        map<int, set<int>> indeg;  
        vector<int> outdegree(n, 0); 

        for (int node = 0; node < n; ++node) {
            for (int neighbor : graph[node]) {
                indeg[neighbor].insert(node);
            }
            outdegree[node] = graph[node].size();
            if (outdegree[node] == 0) {
                result.insert(node);
            }
        }

        queue<int> q;
        for (int terminal : result) {
            q.push(terminal);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int prevNode : indeg[node]) {
                outdegree[prevNode]--;
                if (outdegree[prevNode] == 0) {
                    result.insert(prevNode);
                    q.push(prevNode);
                }
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};