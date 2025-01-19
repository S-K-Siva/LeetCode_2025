#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int rows = heightMap.size();
        int cols = heightMap[0].size();
        vector<vector<bool>> isVisited(rows, vector<bool>(cols, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (row == 0 || row == rows - 1 || col == 0 || col == cols - 1) {
                    minHeap.push({heightMap[row][col], row, col});
                    isVisited[row][col] = true;
                }
            }
        }

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int totalWaterTrapped = 0;

        while (!minHeap.empty()) {
            vector<int> cell = minHeap.top();
            minHeap.pop();
            int currentHeight = cell[0];
            int currentRow = cell[1];
            int currentCol = cell[2];

            for (const auto& direction : directions) {
                int nextRow = currentRow + direction[0];
                int nextCol = currentCol + direction[1];

                if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols && !isVisited[nextRow][nextCol]) {
                    if (currentHeight > heightMap[nextRow][nextCol]) {
                        totalWaterTrapped += currentHeight - heightMap[nextRow][nextCol];
                        minHeap.push({currentHeight, nextRow, nextCol});
                    } else {
                        minHeap.push({heightMap[nextRow][nextCol], nextRow, nextCol});
                    }
                    isVisited[nextRow][nextCol] = true;
                }
            }
        }

        return totalWaterTrapped;
    }
};