class Solution {
public:
    string helper(string str, int left, int right){

        while(left >= 0 && right < str.size() && str[left] == str[right]){
            left--;
            right++;
        }
        return str.substr(left+1, right-left-1);
    }
    string longestPalindrome(string s) {
        string res = s.substr(0,1);
        int n = s.size();
        for(int i = 0;i<n-1;i++){
            string odd,even;
            odd = helper(s,i,i);
            even = helper(s,i,i+1);

            if(odd.size() > res.size()){
                res = odd;
            }
            if(even.size() > res.size()){
                res = even;
            }
        }
        return res;
    }
};