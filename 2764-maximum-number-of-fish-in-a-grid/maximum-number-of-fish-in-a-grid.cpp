class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> vis(row,vector<int>(col,0));
        
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        int maxiResult = 0;
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(!vis[i][j] && grid[i][j] != 0){
                    int count = 0;
                    queue<pair<int,int>> que;
                    que.push({i,j});
                    vis[i][j] = 1;
                    while(!que.empty()){
                        pair<int,int> current = que.front();
                        que.pop();
                        int x = current.first;
                        int y = current.second;
                        
                        count += grid[x][y];
                        
                        for(int k = 0;k<4;k++){
                            int newX = x + dx[k];
                            int newY = y + dy[k];
                            if(newX >= 0 && newY >= 0 &&
                            newX < row && newY < col &&
                            !vis[newX][newY] && grid[newX][newY] != 0){
                                vis[newX][newY] = 1;
                                que.push({newX,newY});
                            }
                        }

                    }
                    maxiResult = max(maxiResult,count);
                }
        }
        }
            
        return maxiResult;
    }
};