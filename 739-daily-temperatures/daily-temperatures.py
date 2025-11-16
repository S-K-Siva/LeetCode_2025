class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        result = []
        track = dict()
        index = len(temperatures) - 1
        for temp in temperatures[::-1]:
            while stack and stack[-1][1] <= temp:
                stack.pop()
            
            if not stack:
                track[index] = 0
            else:
                track[index] = stack[-1][0] - index
            stack.append([index,temp])
            index -= 1

        
        for i in range(len(temperatures)):
            result.append(track[i])
        return result
                