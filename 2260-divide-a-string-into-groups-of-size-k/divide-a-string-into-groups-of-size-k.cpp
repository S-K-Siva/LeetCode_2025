class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int size = s.size();
       
        while(s.size()%k != 0){
            s += fill;
        }
        
        vector<string> result;
        
        for(int i = 0;i<s.size();i+=k){
            result.push_back(s.substr(i,k));
        }
  
        return result;
    }
};