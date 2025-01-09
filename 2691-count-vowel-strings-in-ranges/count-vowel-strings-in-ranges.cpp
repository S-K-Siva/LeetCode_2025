class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
       
        map<char,int> track;
        vector<char> vw = {'a','e','i','o','u'};

        for(auto it : vw){
            ++track[it];
        }
        int n = words.size();
        vector<int> prefixSum(n,0);
        string firstWord = words[0];
        prefixSum[0] = (track[firstWord.front()] && track[firstWord.back()]) ? 1 : 0;

        for(int i = 1;i<n;i++){
            if(track[words[i].front()] && track[words[i].back()]){
                prefixSum[i] = prefixSum[i-1] + 1;
            }else{
                prefixSum[i] = prefixSum[i-1];
            }
        }

        vector<int> result;
        for(auto query : queries){
            int from  = query.front();
            int to = query.back();

            int currentAns = prefixSum[to];
            if(from > 0){
                currentAns -= prefixSum[from - 1];
            }
            result.push_back(currentAns);
        }

        return result;
    }
};