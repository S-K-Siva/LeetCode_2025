class Solution {
public:
    int reverseDegree(string s) {
        int result = 0;
        for(int i = 0;i<s.size();i++){
           
            result += (abs(s[i] - 'z') + 1) * (i+1);
        }
        return result;
    }
};