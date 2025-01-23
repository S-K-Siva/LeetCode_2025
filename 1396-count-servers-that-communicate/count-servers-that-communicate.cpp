class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int,int> trackX;
        unordered_map<int,int> trackY;
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> servers;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    servers.push({i,j});
                    ++trackX[i];
                    ++trackY[j];
                }
            }
        }
        int result = 0;
        while(!servers.empty()){
            pair<int,int> current = servers.front();
            servers.pop();
            
            if(trackX[current.first] > 1 || trackY[current.second] > 1){
                ++result;
            }
        }
        return result;
    }
};