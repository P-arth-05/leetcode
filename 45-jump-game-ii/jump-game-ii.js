/**
 * @param {number[]} nums
 * @return {number}
 */
var jump = function(nums) {
    let ans = 0, currend = 0, furthest = 0;
    for(let i=0; i<nums.length - 1; i++){
        furthest = Math.max(furthest, i + nums[i]);
        if (i === currend){
            ans++;
            currend = furthest;
        }
    } 
    return ans;
};