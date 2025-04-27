class Solution {
public:
    int maxVowels(string s, int k) {
        int n= s.size();
        int result = 0;
        set<char> vowels = {'a','e','i','o','u'}; 
        int track = 0;
        for(int i = 0;i<k && i<n;i++){
            if(vowels.count(s[i])){
                ++track;
            }
        }
        result = max(result, track);
        for(int i = k;i<n;i++){
            if(vowels.count(s[i-k])){
                --track;
            }
            if(vowels.count(s[i])){
                ++track;
            }
            result = max(result, track);
        }
        return result;
    }
};