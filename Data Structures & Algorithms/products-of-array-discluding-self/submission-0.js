class Solution {
    /**
     * @param {number[]} nums
     * @return {number[]}
     */
    productExceptSelf(nums) {
        // if there is > 1 "0" then result is always 0
        // if only there's 1 zero result is all 0 except that 0

        let product = 1;
        const idxZero = [];
        for(let i = 0; i < nums.length; i++) {
            if(nums[i] !== 0) {
                product *= nums[i];
            } else {
                if(idxZero.length > 0) return new Array(nums.length).fill(0);
                idxZero.push(i);
            }
        }

        const output = []
        for (let i = 0; i < nums.length; i++) {
            if(idxZero.length === 0) {
                output.push(product / nums[i]);
            }
            else if(i === idxZero[0]) {
                output.push(product);
            }
            else output.push(0);
        }

        return output;
    }
}
