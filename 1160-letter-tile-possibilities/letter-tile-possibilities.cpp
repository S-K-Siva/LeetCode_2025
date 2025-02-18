class Solution {
public:

    int sol(unordered_map<char,int>& freq){
        int cnt = 0;

        for(auto& key : freq){
            if(key.second > 0){
                key.second--;
                cnt += 1 + sol(freq);
                key.second++;
            }
        }
        return cnt;
    }
    int numTilePossibilities(string tiles) {
        
        unordered_map<char,int> freq;
        for(char ch : tiles){
            ++freq[ch];
        }

        return sol(freq);
    }
};