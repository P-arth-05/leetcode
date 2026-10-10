
var minSumSquareDiff = function(nums1, nums2, k1, k2) {
    let n = nums1.length;
    let k = k1 + k2;
    let diff = new Array(100001).fill(0);

    let maxDiff = 0;

    for (let i = 0; i < n; i++) {
        let d = Math.abs(nums1[i] - nums2[i]);
        diff[d]++;
        maxDiff = Math.max(maxDiff, d);
    }

    // If all differences can be eliminated
    let total = 0;
    for (let d = 1; d <= maxDiff; d++) {
        total += d * diff[d];
    }

    if (k >= total) return 0;

    // Reduce the largest differences first
    for (let d = maxDiff; d > 0 && k > 0; d--) {
        let moves = Math.min(k, diff[d]);

        diff[d] -= moves;
        diff[d - 1] += moves;
        k -= moves;
    }

    let ans = 0;

    for (let d = 1; d <= maxDiff; d++) {
        ans += d * d * diff[d];
    }

    return ans;
};
