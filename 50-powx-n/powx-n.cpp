class Solution {
public:
    double helper(double x, long long int n){
        if(n == 0) return 1.0;
        if(n == 1) return x;
        if(n%2 == 0) return helper(x * x, n/2);
        return x * helper(x, n-1);
    }
    double myPow(double x, int num) {
        long long int n = num;
        if(n < 0) return 1.0/helper(x,-1 * n);
        return helper(x,n);
    }
};