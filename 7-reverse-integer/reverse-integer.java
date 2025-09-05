class Solution {
    public int reverse(int x) {
        boolean isNegative = false;
        if(x < 0) isNegative = true;
        int number = 0;
        while(x != 0){
            
            if(number > (Integer.MAX_VALUE / 10) ||
            number < Integer.MIN_VALUE / 10){
                return 0;
            }
            number = number * 10 + (x%10);

            x/=10;
        }
        return number;
    }
}