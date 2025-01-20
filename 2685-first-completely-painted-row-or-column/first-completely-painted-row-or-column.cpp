class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int> trackCol, trackRow;

        unordered_map<int,pair<int,int>> trackIndex;
        int row = mat.size();
        int col = mat[0].size();

        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                trackIndex[mat[i][j]] = {i,j};
            }
        }
        int i = 0;
        for(auto element : arr){
            pair<int,int> current = trackIndex[element];
            int x = current.first;
            int y = current.second;
            trackRow[x]++;
            trackCol[y]++;
            
            if(trackRow[x] == col || trackCol[y] == row){
                return i;
            }
            ++i;

        }
        return -1;
    }
};