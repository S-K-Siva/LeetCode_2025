class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> arr = {{1},{1,1}};
        if(numRows == 1) return {{1}};
        if(numRows == 2) return {{1},{1,1}};
        vector<int> row;
        for(int i = 2;i<numRows;i++){
            row = arr.back();
            vector<int> newRow;
            newRow.push_back(1);
            for(int i = 0;i<row.size()-1;i++){
                newRow.push_back(row[i] + row[i+1]);
            }
            newRow.push_back(1);
            arr.push_back(newRow);
        }
        return arr;
    }
};