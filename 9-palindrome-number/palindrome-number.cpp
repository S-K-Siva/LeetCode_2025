class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int number = x;
        int compare = 0;
        while(number != 0){
            if((long long int)compare * 10 > INT_MAX) return false;
            compare = compare * 10 + (number % 10);
            number /= 10;
        }
        return compare == x;
    }
};