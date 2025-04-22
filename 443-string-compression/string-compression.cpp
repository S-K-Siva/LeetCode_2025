class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() == 1) return 1;
       string res = "";
       int n = chars.size();
       char ch = chars[0];
       int cnt = 1;
       
       for(int i = 1;i<n;i++){
            if(ch != chars[i]){
                res += ch;
                if(cnt != 1)
                    res += to_string(cnt);
                ch = chars[i];
                cnt = 1;
            }else{
                cnt++;
            }
       }
        res += ch;
        if(cnt != 1)
            res += to_string(cnt);
        int size = res.size();
        for(int i = 0;i<n&&size;i++){
            chars[i] = res[i];
            size--;
        }
        return res.size();
    }
};