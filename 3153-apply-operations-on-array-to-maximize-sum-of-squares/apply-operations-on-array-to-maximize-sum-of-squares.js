/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */

var maxSum = function(nums, k) {
    const MOD = 1000000007n;
    const cnt = new Array(31).fill(0);

    // Count set bits at every position
    for (let num of nums) {
        for (let bit = 0; bit < 31; bit++) {
            if ((num & (1 << bit)) !== 0) {
                cnt[bit]++;
            }
        }
    }

    let ans = 0n;

    // Construct k maximum numbers
    for (let i = 0; i < k; i++) {
        let x = 0;

        for (let bit = 0; bit < 31; bit++) {
            if (cnt[bit] > 0) {
                x |= (1 << bit);
                cnt[bit]--;
            }
        }

        let val = BigInt(x);
        ans = (ans + val * val) % MOD;
    }

    return Number(ans);
};
