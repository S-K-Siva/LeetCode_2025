class Solution {
    public:
        vector<int> color;
        vector<vector<int>> adj;
        int n; 

        bool isBipartite(int node, int c, vector<int>& component) {
            color[node] = c;
            component.push_back(node);
            for (int neigh : adj[node]) {
                if (color[neigh] == c) return false;
                if (color[neigh] == -1 && !isBipartite(neigh, 1 - c, component)) 
                    return false;
            }
            return true;
        }

        int maxGroupsInComponent(const vector<int>& component) {
            int maxDepth = 0;
            for (int start : component) {
                vector<int> depth(n, -1);
                queue<int> q;
                q.push(start);
                depth[start] = 0;
                while (!q.empty()) {
                    int node = q.front(); q.pop();
                    for (int neigh : adj[node]) {
                        if (depth[neigh] == -1) {
                            depth[neigh] = depth[node] + 1;
                            maxDepth = max(maxDepth, depth[neigh]);
                            q.push(neigh);
                        }
                    }
                }
            }
            return maxDepth + 1;
        }


        int magnificentSets(int n, vector<vector<int>>& edges) {
            this->n = n;
            color.assign(n, -1);
            adj.resize(n);
            for (auto& e : edges) {
                int u = e[0] - 1, v = e[1] - 1;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }

            vector<vector<int>> components;
            for (int i = 0; i < n; ++i) {
                if (color[i] == -1) {
                    components.emplace_back();
                    if (!isBipartite(i, 0, components.back())) 
                        return -1; 
                }
            }

            int total = 0;
            for (auto sub : components) 
                total += maxGroupsInComponent(sub);
            
            return total;
        }
};