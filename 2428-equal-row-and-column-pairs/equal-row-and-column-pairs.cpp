class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>,int> track;
        for(int i = 0;i<n;i++){
            vector<int> row;
       
            for(int j = 0;j<n;j++){
                row.push_back(grid[i][j]);
                
            }
            ++track[row];
            
        }
        
        int cnt = 0;
        for(int i = 0;i<n;i++){
            vector<int> col;
            for(int j = 0;j<n;j++){
                col.push_back(grid[j][i]);
            }
            if(track.find(col) != track.end()){
                cnt += track[col];
            }
        }
        return cnt;
    }
};