class Solution {
public:
    int lastRemaining(int n) {
        int step = 1;
        int rem = n;
        int res = 1;
        bool leftToRight = true;
        while(rem > 1){
            if(leftToRight || rem % 2 == 1){
                res += step;
            }
            step *= 2;
            rem/=2;
            leftToRight = !leftToRight;
        }
        return res;
    }
};