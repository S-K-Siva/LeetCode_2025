class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int result = 0;

        for(auto word : words){
            int prefSize = pref.size();
            if(word.size() < prefSize) continue;
            string prefix = word.substr(0,prefSize);
            result += (prefix == pref) ? 1 : 0;
        }
        return result;
    }
};