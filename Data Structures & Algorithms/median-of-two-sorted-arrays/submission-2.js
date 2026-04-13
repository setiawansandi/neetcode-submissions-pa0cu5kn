class Solution {
    /**
     * @param {number[]} nums1
     * @param {number[]} nums2
     * @return {number}
     */
    findMedianSortedArrays(nums1, nums2) {
        let newArr = []
        let mid = Math.floor((nums1.length + nums2.length)/2)

        let i = 0
        let j = 0
        
        while (i < nums1.length && j < nums2.length && newArr.length !== mid+1) {
            if(nums1[i] < nums2[j]) {
                newArr.push(nums1[i])
                i++
            } else {
                newArr.push(nums2[j])
                j++
            }
        }

        while(i < nums1.length && newArr.length !== mid+1) {
            newArr.push(nums1[i])
            i++
        }

        while(j < nums2.length && newArr.length !== mid+1) {
            newArr.push(nums2[j])
            j++
        }

        if((nums1.length + nums2.length) % 2 === 0) {
            return (newArr[mid] + newArr[mid-1]) / 2
        }
        return (newArr[mid])
    }
}
