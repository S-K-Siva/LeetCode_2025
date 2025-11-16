class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result = []
        stack = []
        track = dict()

        for num in nums2[::-1]:
            while stack and stack[-1] <= num:
                stack.pop()
            
            if not stack:
                track[num] = -1
            else:
                track[num] = stack[-1]
            stack.append(num)

        for num in nums1:
            result.append(track[num])
        return result