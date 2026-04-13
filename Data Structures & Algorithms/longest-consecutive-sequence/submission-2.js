class Solution {
    /**
     * @param {number[]} nums
     * @return {number}
     */
    longestConsecutive(nums) {
        if (nums.length === 0) return 0;

        let longest = 0;
        let count = 1
        nums.sort((a, b) => a - b);
        console.log(nums)
        
        for(let i = 1; i < nums.length; i++) {
            if(nums[i] - nums[i-1] === 1) {
                count++;
            } else if(nums[i] - nums[i-1] > 1) {
                longest = Math.max(count, longest);
                count = 1
            }
        }

        longest = Math.max(count, longest);
        return longest
    }
}
