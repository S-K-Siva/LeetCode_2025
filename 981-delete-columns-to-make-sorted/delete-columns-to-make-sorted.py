class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        m = len(strs[0])
        n = len(strs)
        cnt = 0
        for i in range(m):
            s = ""
            for j in range(n):
                s += strs[j][i]
            if s != ''.join(sorted(s)):
                cnt += 1
        
        return cnt
