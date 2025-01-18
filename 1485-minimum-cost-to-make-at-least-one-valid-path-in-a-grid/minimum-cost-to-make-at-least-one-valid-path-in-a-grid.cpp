class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        pq.push({0, {0, 0}});
        
        while (!pq.empty()) {
            pair<int, pair<int, int>> current = pq.top();
            pq.pop();
            int cost = current.first;
            int x = current.second.first;
            int y = current.second.second;
            
            if (visited[x][y]) continue;
            visited[x][y] = true;
            
            if (x == m - 1 && y == n - 1) return cost;
            
            for (int d = 0; d < 4; ++d) {
                int newX = x + dx[d];
                int newY = y + dy[d];
                int newCost = grid[x][y] == d + 1 ? cost : cost+1;

                if (newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY]) {
                    pq.push({newCost, {newX, newY}});
                }
            }
        }
        return -1;
    }
};