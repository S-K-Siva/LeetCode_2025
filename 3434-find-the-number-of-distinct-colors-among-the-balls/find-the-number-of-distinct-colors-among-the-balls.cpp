class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> trackIndex; 
        unordered_map<int, int> trackColour; 
        vector<int> result;

        for (auto row : queries) {
            int ball = row[0];
            int color = row[1];

            if (trackIndex.find(ball) != trackIndex.end()) {
                int previousColor = trackIndex[ball];
                
                if (previousColor == color) {
                    result.push_back(trackColour.size());
                    continue;
                }

                if (--trackColour[previousColor] == 0) {
                    trackColour.erase(previousColor);
                }
            }

            trackIndex[ball] = color;
            trackColour[color]++;

            result.push_back(trackColour.size());
        }

        return result;
    }
};