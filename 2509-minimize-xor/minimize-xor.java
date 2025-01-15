class Solution {
    public int minimizeXor(int num1, int num2) {
        int num1Cnt = Integer.bitCount(num1);
        int num2Cnt = Integer.bitCount(num2);

        int result = num1;
        for(int i = 0;i<32;i++){
            int divisor = (int) Math.pow(2,i);
            int value = (num1 / divisor) % 2;
            int resValue = (result / divisor) % 2;
            if(num1Cnt > num2Cnt && value > 0){
                if(resValue == 1){
                    result -= divisor;
                    num1Cnt--;
                }
            }
            if(num1Cnt < num2Cnt && value == 0)
            {
                if(resValue == 0){
                    result += divisor;
                    num1Cnt++;
                }
            }
        }
        return result;
    }
}