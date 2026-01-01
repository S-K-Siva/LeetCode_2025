class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        num = 0
        for digit in digits:
            num = (num * 10) + digit
        num += 1
        lst = []

        while num:
            r = num%10
            lst.append(r)
            num //= 10
        lst = lst[::-1]
        return lst