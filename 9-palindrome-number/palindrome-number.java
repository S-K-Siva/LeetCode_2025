class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0) return false;
        int number = x;

        int compare = 0;
        while(number != 0){
            if((long)compare * 10 > Integer.MAX_VALUE) return false;
            compare = compare * 10 + (number % 10);
            number /=10;
        }
        return x == compare;
    }
}