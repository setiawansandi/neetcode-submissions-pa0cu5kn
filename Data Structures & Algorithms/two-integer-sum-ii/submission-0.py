class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        head = 0;
        tail = -1;

        while True:
            sum = numbers[head] + numbers[tail]
            if sum < target:
                head += 1;
            elif sum > target:
                tail -= 1;
            else:
                return [head+1, len(numbers)+tail+1]

