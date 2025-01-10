// TLE (39/56)
// class Solution {
// public:
//     vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
//         vector<string> result;
//         unordered_map<string, map<char,int>> track;
//         for(auto word : words1){

//             map<char,int> freq;
//             for(int i = 0;i<word.size();i++){
//                 ++freq[word[i]];
//             }
//             track[word] = freq;
//         }
//         map<string,map<char,int>> letterFreq;
//         for(auto word : words2){
//             map<char,int> freq;
//             for(int i = 0;i<word.size();i++){
//                 ++freq[word[i]];
//             }
//             letterFreq[word] = freq;
//         }
//         for(auto word : words1){
//             bool possible = true;
//             map<char,int> freq = track[word];
//             for(auto letter : words2){
//                 map<char,int> lf = letterFreq[letter];
//                 for(auto it : lf){
//                     if(it.second > freq[it.first]){
//                         possible = false;
//                         break;
//                     }
//                 }
//             }
//             if(possible){
//                 result.push_back(word);
//             }
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;
        vector<int> maxFreq(26, 0);
        for (auto word : words2) {
            vector<int> freq(26, 0);
            for (char ch : word) {
                freq[ch - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }

        for (auto word : words1) {
            vector<int> freq(26, 0);
            for (char ch : word) {
                freq[ch - 'a']++;
            }
            bool isPossible = true;
            for (int i = 0; i < 26; ++i) {
                if (freq[i] < maxFreq[i]) {
                    isPossible = false;
                    break;
                }
            }
            if (isPossible) {
                result.push_back(word);
            }
        }

        return result;
    }
};