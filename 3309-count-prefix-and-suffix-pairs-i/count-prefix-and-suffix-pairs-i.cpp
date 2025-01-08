class Solution {
public:

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int result = 0;
        for(int i = 0;i<n;i++)
        {
            string w1 = words[i];
            for(int j = i+1;j<n;j++){
                string w2 = words[j];
                if(w2.length() < w1.length()) continue;
                string prefix = w2.substr(0,w1.length());
                string suffix = w2.substr(w2.length()-w1.length());

                if(prefix == w1 && suffix == w1){
                    result++;
                }
            }
        }
        return result;
    }
};