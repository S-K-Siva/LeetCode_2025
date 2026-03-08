class Solution {
public:
    string solve(string current,int size, vector<char> binary, unordered_map<string,int>& track){
        if(current.size() == size){
            if(track.find(current) == track.end()){
                return current;
            }
            return "";
        }
        for(int i = 0;i<2;i++){
            string res = solve(current + binary[i], size, binary, track);
            if(res != "") return res;
        }
        return "";
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,int> track;
        for(auto it : nums){
            ++track[it];
        }
        int size = nums.front().size();
        vector<char> binary = {'1','0'};
        return solve("", size, binary, track);
    }
};