class Solution {
    public int minimumLength(String s) {
        int n = s.length();
        if(n <= 2) return n;
        int[] freq = new int[256];

        for(int i = 0;i<n;i++){
            ++freq[s.charAt(i)];
        }

        int result = 0;
        for(int i = 0;i<256;i++){
            if(freq[i] <= 2){
                result += freq[i];
            }else if(freq[i] % 2 == 0){
                result += 2;
            }else{
                result += 1;
            }
        }
        return result;
    }
}