class Solution {
public:
    int binaryGap(int n) {
        string binString = "";
        
        int num = n;
        while(num != 0){
            if(num % 2 == 1){
                binString = '1' + binString;
            }else{
                binString = '0' + binString;
            }
            num /= 2;
        }
        
        vector<int> prefix(binString.size(),-1);
        if(binString[0] == '1'){
            prefix[0] = 0;
        }
        for(int i = 1;i<binString.size();i++){
            if(binString[i] == '1'){
                prefix[i] = i;
            }else{
                prefix[i] = prefix[i-1];
            }
        }
        int result = 0;
        for(int i = 1;i<binString.size();i++){
            if(binString[i] == '1'){
                result = max(result, i-prefix[i-1]);
            }
        }
        return result;
    }
};