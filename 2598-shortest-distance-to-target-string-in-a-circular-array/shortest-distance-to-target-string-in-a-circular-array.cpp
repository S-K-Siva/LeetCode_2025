class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int result = INT_MAX;
        int n = words.size();
        for(int i = 0;i<n;i++){
            if(words[i] == target){
                int clockwise = (i - startIndex + n) % n;
                int anticlockwise = (startIndex - i + n) % n;
                int dist = min(clockwise, anticlockwise);
                result = min(result,dist);
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};