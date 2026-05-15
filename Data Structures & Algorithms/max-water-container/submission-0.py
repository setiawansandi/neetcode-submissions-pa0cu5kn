class Solution:
    def maxArea(self, heights: List[int]) -> int:
        head = 0
        tail = len(heights) - 1
        max_area = 0

        while head < tail:
            max_area = max(max_area, (tail-head) * min(heights[head], heights[tail]))
            if heights[head] < heights[tail]:
                head += 1
            else:
                tail -= 1
        
        return max_area