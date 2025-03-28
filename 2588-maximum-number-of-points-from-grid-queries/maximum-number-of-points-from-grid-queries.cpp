class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        // TLE
        // int m = grid.size();
        // int n = grid[0].size();
        
        // vector<int> dx = {1,-1,0,0};
        // vector<int> dy = {0,0,1,-1};
        // vector<int> result;
        // for(auto value : queries){
        //     vector<vector<int>> vis(m,vector<int>(n,0));
        //     queue<pair<int,int>> que;
        //     que.push({0,0});
        //     while(!que.empty()){
        //         pair<int,int> current = que.front();
        //         que.pop();
        //         int x = current.first;
        //         int y = current.second;
                
        //         if(grid[x][y] < value){
        //             vis[x][y] = 1;
        //             for(int i = 0;i<4;i++){
        //                 int newX = x + dx[i];
        //                 int newY = y + dy[i];
        //                 if(newX >= 0 && newX < m &&
        //                 newY >= 0 && newY < n && 
        //                 !vis[newX][newY]){
        //                     que.push({newX,newY});
        //                 }
        //             }
        //         }
        //     }

        //     int cnt = 0;
        //     for(int i = 0;i<m;i++){
        //         for(int j = 0;j<n;j++){
        //             if(vis[i][j]) cnt++;
        //         }
        //     }
        //     result.push_back(cnt);
        // }
        // return result;

        int m = grid.size(), n = grid[0].size();
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        vector<int> sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end());

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[0][0] = true;

        int count = 0;  // Number of reachable cells
        unordered_map<int, int> queryResults; // Store results for each query
        
        for (int query : sortedQueries) {
            while (!pq.empty() && pq.top().first < query) {
                auto [val, cell] = pq.top();
                pq.pop();
                count++;  // A new cell is reachable
                
                int x = cell.first, y = cell.second;
                for (int i = 0; i < 4; i++) {
                    int newX = x + dx[i], newY = y + dy[i];
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && !vis[newX][newY]) {
                        pq.push({grid[newX][newY], {newX, newY}});
                        vis[newX][newY] = true;
                    }
                }
            }
            queryResults[query] = count;
        }

        vector<int> result;
        for (int q : queries) {
            result.push_back(queryResults[q]);
        }
        return result;
    }
};