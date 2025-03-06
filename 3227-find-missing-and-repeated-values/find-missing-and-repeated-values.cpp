class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> track;
        int n = grid.size();
        int maxVal = n*n;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                ++track[grid[i][j]];
                maxVal = max(maxVal, grid[i][j]);
            }
        }
        int repeated = -1;
        int missing = -1;
        for(int i = 1;i<=maxVal && (repeated == -1 || missing == -1);i++){
            if(track.find(i) == track.end()){
                missing = i;
            }
            if(track.find(i) != track.end() && track[i] > 1){
                repeated = i;
            }
        }

        return {repeated,missing};
    }
};