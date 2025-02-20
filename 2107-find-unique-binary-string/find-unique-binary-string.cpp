class Solution {
public:


    string construct(string curr, vector<char> bins,int maxSize,
    unordered_map<string,int> mpp){
        if(curr.size() == maxSize){
            if(mpp.find(curr) == mpp.end()){
                return curr;
            }
            return "";
        }
        for(int i = 0;i<bins.size();i++){
            if(curr.empty() || curr.size() < maxSize){
                string value = construct(curr+bins[i],bins,maxSize,mpp);
                if(value != "" && !mpp[value] ){
                    return value;
                }
            }
        }
        return "";
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int Size = nums[0].size();
        vector<char> bins = {'1','0'};
        unordered_map<string,int> track;
        for(auto binary : nums){
            ++track[binary];
        }
        string res = construct("",bins,Size,track);
        if(res != "") return res;
        return "";
    }
};