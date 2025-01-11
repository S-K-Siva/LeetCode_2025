class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.size()) return false;
        unordered_map<char,int> freq;
        for(int i = 0;i<s.size();i++){
            ++freq[s[i]];
        }
        int cnt = 0;
        for(auto it : freq){
            if(it.second % 2 == 1){
                ++cnt;
            }
        }
        
        return cnt <= k;
    }
};