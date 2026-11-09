class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int start = 0;
        int end = k;

        int leastDiffSum = 0;

        for (int i = 0; i < k; i++) {
            leastDiffSum += Math.abs(arr[i] - x);
        }


        int ansStart = 0;
        int ansEnd = k;

        int diffSum = leastDiffSum;

        while (end < arr.length) {
            diffSum += Math.abs(arr[end] - x);
            end++;
            diffSum -= Math.abs(arr[start] - x);
            start++;

            if (diffSum < leastDiffSum) {
                ansStart = start;
                ansEnd = end;

                leastDiffSum = diffSum;
            }
        }

        ArrayList<Integer> ans = new ArrayList<>();

        for (int i = ansStart; i < ansEnd; i++) {
            ans.add(arr[i]);
        }

        return ans;
    }
}