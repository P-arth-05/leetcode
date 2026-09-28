/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let freq = new Map();

    for (let x of nums) {
        if (!freq.has(x)) {
            freq.set(x, 1);
        } else {
            freq.set(x, freq.get(x) + 1);
        }

        if (freq.get(x) > nums.length / 2) {
            return x;
        }
    }
};