class Solution {
    public String longestCommonPrefix(String[] strs) {
        int length = Integer.MAX_VALUE;
        for(String str : strs){
            length = Math.min(str.length(), length);
        }
        int i;
        for(i = 0;i<length;i++){
            char ch = strs[0].charAt(i);
            boolean allHave = true;
            for(int j = 1;j<strs.length;j++){
                if(strs[j].charAt(i) != ch){
                    allHave = false;
                    break;
                }
            }
            if(!allHave) break;
        }
        return strs[0].substring(0,i);
    }
}