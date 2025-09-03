class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      
        int length = INT_MAX;
        for(int i =0;i<strs.size();i++){
            length = min((int)length,(int)strs[i].size());
        }
        int i;
        for(i = 0;i<length;i++){
            char ch = strs[0][i];
            bool allHave = true;
            for(int j = 1;j<strs.size();j++){
                if(strs[j][i] != ch){
                    allHave = false;
                    break;
                }
            }
            if(!allHave) break;
        }
        return strs[0].substr(0,i);
    }
};