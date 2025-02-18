class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        vector<int> st(n+1,0);
        int index = 0;
        string result = "";
        for(int i = 0;i<=n;i++){
            st[index++] = i + 1;
            if(i == n || pattern[i] == 'I'){
                while(index > 0){
                    result += to_string(st[--index]);
                }
            }
        }
        return result;
    }
};