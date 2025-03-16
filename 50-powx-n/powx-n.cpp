class Solution {
public:

    double solve(double x, long long int n){
        if(n == 0) return 1.0;
        if(n == 1) return x;

        if(n%2 == 0) return solve(x*x, n/2);

        return x * solve(x,n-1);
    }
    double myPow(double x, int n) {
        long long int num = n;
        if(num < 0){
            return (1.0/solve(x,-1*num));
        }
        return solve(x,num);
    }
};