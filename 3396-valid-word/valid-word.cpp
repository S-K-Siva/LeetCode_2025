class Solution {
public:
    bool isValid(string word) {
        map<char,int> digits,vowels;
        
        vector<char> chars = {'a','e','i','o','u','A','E','I','O','U'};
        for(int i = 0;i<10;i++){
            digits[i + '0']++;
        }
        for(auto it : chars){
            vowels[it]++;
        }
        bool isUpper,isLower,oneVowel,oneConsonant, somethingelse, isDigit;
        isUpper = isLower = oneVowel = oneConsonant = somethingelse = isDigit = false;

        for(int i = 0;i<word.size();i++){
            if(isupper(word[i])){
                isUpper = true;
            }
            if(islower(word[i])){
                isLower = true;
            }
            if(digits[word[i]]){
                isDigit = true;
                continue;
            }
            if(vowels[word[i]]){
                oneVowel = true;
            }else{
                int asciiValue = (int)word[i];
                if((asciiValue >= 65 && asciiValue <= 90) ||
                (asciiValue >= 97 && asciiValue < 123)){
                    oneConsonant = true;
                }else{
                    return false;
                }
            }

            
        }
        
        return word.size() >= 3 && oneVowel && oneConsonant;
    }
};