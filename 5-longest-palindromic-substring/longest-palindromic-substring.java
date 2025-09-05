class Solution {
    public String helper(String s, int l, int r){
        while(l>=0 && r<s.length() && s.charAt(l) == s.charAt(r)){
            l--;
            r++;
        }
        return s.substring(l+1,r);
    }
    public String longestPalindrome(String s) {
        String result = "";
        for(int i = 0;i<s.length();i++){
            String odd = helper(s,i,i);
            String even = helper(s,i,i+1);
            if(odd.length() > result.length()){
                result = odd;
            }
            if(even.length() > result.length()){
                result = even;
            }
        }
        return result;
    }
}