class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals.length <= 1) return intervals;

        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

        List<int[]> out = new ArrayList<>();
        int[] cur = intervals[0];
        out.add(cur);

        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] <= cur[1]) {          // overlaps
                cur[1] = Math.max(cur[1], intervals[i][1]);
            } else {
                cur = intervals[i];
                out.add(cur);
            }
        }
        return out.toArray(new int[out.size()][]);
    }
}