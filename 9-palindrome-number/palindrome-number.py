class Solution:
    def isPalindrome(self, x: int) -> bool:
        X = str(x)
        if x < 0:
            return False
        return X == X[::-1]