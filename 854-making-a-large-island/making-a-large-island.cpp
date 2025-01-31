class Solution {
public:
    int findParent(int node, vector<int>& parent) {
        if (parent[node] != node) parent[node] = findParent(parent[node], parent);
        return parent[node];
    }

    void unionSets(int x, int y, vector<int>& parent, vector<int>& size) {
        int parentOfX = findParent(x, parent);
        int parentOfY = findParent(y, parent);
        if (parentOfX != parentOfY) {
            parent[parentOfY] = parentOfX;
            size[parentOfX] += size[parentOfY];
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> parent(n * n, -1);
        vector<int> size(n * n, 1);
        int maxIsland = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int idx = i * n + j;
                    parent[idx] = idx;
                    if (i > 0 && grid[i-1][j] == 1) unionSets(idx, (i-1)*n + j, parent, size);
                    if (j > 0 && grid[i][j-1] == 1) unionSets(idx, i*n + (j-1), parent, size);
                    maxIsland = max(maxIsland, size[findParent(idx, parent)]);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighbors;
                    int currentSize = 1;
                    if (i > 0 && grid[i-1][j] == 1) neighbors.insert(findParent((i-1)*n + j, parent));
                    if (j > 0 && grid[i][j-1] == 1) neighbors.insert(findParent(i*n + (j-1), parent));
                    if (i < n-1 && grid[i+1][j] == 1) neighbors.insert(findParent((i+1)*n + j, parent));
                    if (j < n-1 && grid[i][j+1] == 1) neighbors.insert(findParent(i*n + (j+1), parent));
                    for (int neighbor : neighbors) currentSize += size[neighbor];
                    maxIsland = max(maxIsland, currentSize);
                }
            }
        }

        return maxIsland;
    }

    
};