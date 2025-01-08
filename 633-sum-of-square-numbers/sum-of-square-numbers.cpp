class Solution {
public:
    bool judgeSquareSum(int c) {
        int low = 0;
        int high = sqrt(c);
        while(low <= high){
            
            if((long) low*low + (long)high*high == (long) c){
                return true;
            }else if((long)low*low + (long)high*high < (long) c){
                ++low;
            }else{
                --high;
            }
        }
        return false;
    }
};