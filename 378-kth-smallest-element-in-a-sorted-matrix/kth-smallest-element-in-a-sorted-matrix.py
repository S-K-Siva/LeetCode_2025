class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)
        minHeap = []
        for i in range(n):
            heapq.heappush(minHeap, (matrix[i][0],i,0))
        
        track = 0
        while minHeap:
            value, row, column = heapq.heappop(minHeap)
            track += 1
            if track == k:
                return value
            if column + 1 < n:
                heapq.heappush(minHeap, (matrix[row][column+1], row, column+1))
        return -1