class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        maxHeap = []
        for element in nums:
            heapq.heappush(maxHeap,-element)
        
        count = 0
        while maxHeap:
            value = heapq.heappop(maxHeap)
            count += 1 
            if count == k:
                return -value
        return -1